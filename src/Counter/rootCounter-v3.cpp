// Worker thread
void worker(const std::vector<int> & degrees,
            const std::vector<int> & genera,
            const std::vector<std::vector<int>> & nodal_edges,
            const int & root,
            const std::vector<std::vector<std::vector<int>>> & graph_stratification,
            const std::vector<std::vector<int>> & outfluxes,
            const std::vector<bool> & lower_bounds,
            std::vector<boost::multiprecision::int128_t> & sums,
            std::vector<std::vector<std::vector<int>>> & unsorted_setups)
{
    
    // determine number of local roots
    int number_elliptic_curves = std::count(genera.begin(), genera.end(), 1);
    boost::multiprecision::int128_t number_local_roots = (boost::multiprecision::int128_t) std::pow(root,2*number_elliptic_curves);
    
    // save total number of roots found
    boost::multiprecision::int128_t total_clear = 0;
    boost::multiprecision::int128_t total_unclear = 0;
    
    // count weight assignments
    struct comb_data{
        std::vector<int> flux;
        int k;
        boost::multiprecision::int128_t mult;
    };
    for (int i = 0; i < outfluxes.size(); i++){
        
        // create stack
        std::stack<comb_data> snapshotStack;
        
        // add first snapshot
        comb_data currentSnapshot;
        currentSnapshot.flux = outfluxes[i];
        currentSnapshot.k = 0;
        currentSnapshot.mult = (boost::multiprecision::int128_t) 1;
        snapshotStack.push(currentSnapshot);
        
        // Run...
        while(!snapshotStack.empty())
        {
        
            // pick the top snapshot and delete it from the stack
            currentSnapshot= snapshotStack.top();
            snapshotStack.pop();
            
            // action required...
            if (currentSnapshot.k < graph_stratification.size()){
                
                // gather data
                int N = currentSnapshot.flux[currentSnapshot.k];
                int n = graph_stratification[currentSnapshot.k][0].size();
                std::vector<int> minima, maxima;
                minima.reserve(degrees.size());
                maxima.reserve(degrees.size());
                for (int j = 0; j < n; j++){
                    int vertex_number = graph_stratification[currentSnapshot.k][0][j];
                    int number_of_attached_resolved_edges = graph_stratification[currentSnapshot.k][1][j];
                    int remaining_resolved_edges = graph_stratification[currentSnapshot.k][2][j];
                    int min = number_of_attached_resolved_edges;
                    int f_other = currentSnapshot.flux[vertex_number];
                    if (min < number_of_attached_resolved_edges * root - (f_other - remaining_resolved_edges)){
                        min = number_of_attached_resolved_edges * root - (f_other - remaining_resolved_edges);
                    }
                    int max = number_of_attached_resolved_edges * (root-1);
                    minima.push_back(min);
                    maxima.push_back(max);
                }
                
                // compute flux_partitions
                if (N == 0 && n == 0){
                    
                    // all weights set, just increase k
                    comb_data newSnapshot;
                    newSnapshot.flux = currentSnapshot.flux;
                    newSnapshot.mult = currentSnapshot.mult;
                    newSnapshot.k = currentSnapshot.k + 1;
                    snapshotStack.push(newSnapshot);
                    
                }
                else{
                    
                    // not all weights are determined -> iterate over flux_partitions
                    std::vector<std::vector<int>> flux_partitions;
                    comp_partitions(N, n, minima, maxima, flux_partitions);

                    // create new snapshots
                    std::vector<int> number_of_resolved_edges = graph_stratification[currentSnapshot.k][1];
                    for(int j = 0; j < flux_partitions.size(); j++){

                        // create data of new snapshot (in particular the number of subpartitions)
                        boost::multiprecision::int128_t mult = currentSnapshot.mult;
                        std::vector<int> new_flux(currentSnapshot.flux.begin(), currentSnapshot.flux.end());
                        new_flux[currentSnapshot.k] = 0;
                        for (int a = 0; a < n; a++){
                            int index = graph_stratification[currentSnapshot.k][0][a];
                            new_flux[index] = new_flux[index] - (root * graph_stratification[currentSnapshot.k][1][a] - flux_partitions[j][a]);
                            mult = mult * number_partitions(flux_partitions[j][a], number_of_resolved_edges[a], root);
                        }

                        // add snapshot
                        comb_data newSnapshot;
                        newSnapshot.flux = new_flux;
                        newSnapshot.mult = mult;
                        newSnapshot.k = currentSnapshot.k + 1;
                        snapshotStack.push(newSnapshot);
                        
                    }
                    
                }
                
            }
            // no action required
            else{
                
                if (lower_bounds[i]){
                    
                    // Iterate over the connected components, find out if isolated g = 1 curves prevent us from computing h0 precisely and save all unsorted setups
                    bool only_isolated_elliptic_curves_cause_trouble = true;
                    std::vector<int> normalized_degrees;
                    for (int j = 0; j < degrees.size(); j++){
                        normalized_degrees.push_back((int)((degrees[j] - outfluxes[i][j])/root));
                    }
                    std::vector<std::vector<std::vector<int>>> edges_of_cc;
                    std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
                    find_connected_components(nodal_edges, normalized_degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
                    for (int j = 0; j < edges_of_cc.size(); j++){
                        bool lower_bound_for_cc;
                        int h0_of_cc = h0_on_nodal_curve(degs_of_cc[j], edges_of_cc[j], gens_of_cc[j], lower_bound_for_cc);
                        if (lower_bound_for_cc){
                            
		                    // We want to know if the only issue with computing h0 are isolated g = 1 curves. It is sufficient to check if there are more than a single component.
		                    if (degs_of_cc[j].size() > 1){
				                only_isolated_elliptic_curves_cause_trouble = false;
		                    }
                            
                            // How many rational and elliptic curves?
                            int number_rational = 0;
                            int number_elliptic = 0;
                            for (int k = 0; k < gens_of_cc[j].size(); k++){
                                if (gens_of_cc[j][k] == 0){
                                    number_rational++;
                                }
                                if (gens_of_cc[j][k] == 1){
                                    number_elliptic++;
                                }
                            }
                            
                            // Standardize the graph
                            std::vector<int> new_degrees, new_genera;
                            std::vector<std::vector<int>> new_edges;
                            int offset = standardize(degs_of_cc[j], edges_of_cc[j], gens_of_cc[j], new_degrees, new_edges, new_genera);
                            
                            // Identify the connected components
                            std::vector<std::vector<std::vector<int>>> standardized_edges_of_cc;
                            std::vector<std::vector<int>> standardized_degs_of_cc, standardized_gens_of_cc;
                            find_connected_components(new_edges, new_degrees, new_genera, standardized_edges_of_cc, standardized_degs_of_cc, standardized_gens_of_cc);
                            
                            // Iterate over the standardized connected components
                            for (int k = 0; k < standardized_edges_of_cc.size(); k++){
                                bool lower_bound_test = false;
                                int sections = h0_on_standardized_connected_nodal_curve(standardized_degs_of_cc[k], standardized_edges_of_cc[k], standardized_gens_of_cc[k], lower_bound_test);
                                if (lower_bound_test){
                                    std::vector<std::vector<int>> new_unsorted_setup = {standardized_gens_of_cc[k], standardized_degs_of_cc[k], {sections}};
                                    for (int l = 0; l < standardized_edges_of_cc[k].size(); l++){
                                        new_unsorted_setup.push_back(standardized_edges_of_cc[k][l]);
                                    }
                                    UpdateUnsortedThreadSafe(unsorted_setups, new_unsorted_setup);
                                }
                            }
                            
                        }
                    }
                    
                    // If the only issue with computing h0 on this nodal curve are isolated g = 1 curves, then we can provide a more precise update on our root counters.
                    if (only_isolated_elliptic_curves_cause_trouble){
		                boost::multiprecision::int128_t number_of_roots_on_isolated_elliptic_curves_with_precise_h0 = 1;
		                for (int j = 0; j < normalized_degrees.size(); j++){
				            if (genera[j] == 1 and normalized_degrees[j] != 0){
						        number_of_roots_on_isolated_elliptic_curves_with_precise_h0 = number_of_roots_on_isolated_elliptic_curves_with_precise_h0 * (boost::multiprecision::int128_t) (root * root);
				            }
				            if (genera[j] == 1 and normalized_degrees[j] == 0){
						        number_of_roots_on_isolated_elliptic_curves_with_precise_h0 = number_of_roots_on_isolated_elliptic_curves_with_precise_h0 * (boost::multiprecision::int128_t) (root * root - 1);
				            }
		                }
		                total_clear += (boost::multiprecision::int128_t) currentSnapshot.mult * number_of_roots_on_isolated_elliptic_curves_with_precise_h0;
		                total_unclear += (boost::multiprecision::int128_t) currentSnapshot.mult * (number_local_roots - number_of_roots_on_isolated_elliptic_curves_with_precise_h0);
		            }
		            else{
				        total_unclear += (boost::multiprecision::int128_t) currentSnapshot.mult * number_local_roots;
		            }
                }
                else{
                    total_clear += (boost::multiprecision::int128_t) currentSnapshot.mult * number_local_roots;
                }
                
            }
            
        }
        
    }
    
    // Update result
    UpdateCountThreadSafe(sums, total_clear, total_unclear);
    
}



// Count number of root bundles with prescribed number of sections
std::vector<boost::multiprecision::int128_t> root_counter(
                                const std::vector<int> & degrees,
                                const std::vector<int> & genera,
                                const std::vector<std::vector<int>> & resolved_edges,
                                const std::vector<std::vector<int>> & nodal_edges,
                                const int & root,
                                const std::vector<std::vector<std::vector<int>>> & graph_stratification,
                                const std::vector<int> & edge_numbers,
                                const int & h0_value,
                                std::vector<std::vector<std::vector<int>>> & unsorted_setups)
{
    
    // (0) Define local variables and types
    // (0) Define local variables and types
    std::vector<std::vector<int>> local_degree_distributions, outfluxes;
    std::vector<bool> lower_bounds, lbs;
    struct flux_data{
        std::vector<int> flux;
    };
    
    
    // (1) Find the maximal number of local sections on each curve
    // (1) Find the maximal number of local sections on each curve
		std::vector<int> maximal_local_sections;
		for (int i = 0; i < degrees.size(); i++){
				if (degrees[i] - edge_numbers[i] < 0){
						maximal_local_sections.push_back(0);
				}
				else{
						int d = (degrees[i] - edge_numbers[i]) / root;
						if (genera[i] == 1 && d == 0){
								maximal_local_sections.push_back(1);
						}
						else{
								maximal_local_sections.push_back(d  - genera[i] + 1);
						}
				}
		}
		
		
    // (2) Find the minimal number of local sections on each curve
    // (2) Find the minimal number of local sections on each curve
		std::vector<int> minimal_local_sections;
		for (int i = 0; i < degrees.size(); i++){
				if (degrees[i] - (root-1) * edge_numbers[i] < 0){
						minimal_local_sections.push_back(0);
				}
				else{
						int d = (degrees[i] - (root-1) * edge_numbers[i]) / root;
						if (genera[i] == 1 && d == 0){
								minimal_local_sections.push_back(0);
						}
						else{
								minimal_local_sections.push_back(d  - genera[i] + 1);
						}
				}
		}
		
		
    // (2) Partition h0
    // (2) Partition h0
    distribute_global_sections(h0_value, nodal_edges, genera, minimal_local_sections, maximal_local_sections, local_degree_distributions, lower_bounds);
    
    
    // (3) Find fluxes corresponding to distribution of local sections
    // (3) Find fluxes corresponding to distribution of local sections
    for (int i = 0; i < local_degree_distributions.size(); i++){
        
        // create stack and first snapshot
        std::stack<flux_data> snapshotStack;
        flux_data currentSnapshot;
        currentSnapshot.flux = {};
        snapshotStack.push(currentSnapshot);
        
        // Run...
        while(!snapshotStack.empty()){
        
            // pick the top snapshot and delete it from the stack
            currentSnapshot= snapshotStack.top();
            snapshotStack.pop();
            
            // any fluxes to be set?
            if (currentSnapshot.flux.size() < degrees.size()){
                
                // determine vertex for which we determine the outflux
                int j = currentSnapshot.flux.size();
                
                // determine the possible fluxes
                if (local_degree_distributions[i][j] >= 0){
                    int f = degrees[j] - root * local_degree_distributions[i][j];
                    if ((edge_numbers[j] <= f) && (f <= edge_numbers[j] * (root-1)) && ((degrees[j] - f) % root == 0)){
                        std::vector<int> new_flux = currentSnapshot.flux;
                        new_flux.push_back(f);
                        flux_data newSnapshot;
                        newSnapshot.flux = new_flux;
                        snapshotStack.push(newSnapshot);
                    }
                }
                else{
                    int min_flux = degrees[j] + 1;
                    if (min_flux < edge_numbers[j]){
                        min_flux = edge_numbers[j];
                    }
                    for (int k = min_flux; k <= edge_numbers[j]*(root-1); k++){
                        if ((degrees[j] - k) % root == 0){
                            std::vector<int> new_flux = currentSnapshot.flux;
                            new_flux.push_back(k);
                            flux_data newSnapshot;
                            newSnapshot.flux = new_flux;
                            snapshotStack.push(newSnapshot);
                        }
                    }
                }
                
            }
            // no more fluxes to be set --> add to list of fluxes if the sum of fluxes equals the number of resolved_edges * root (necessary and sufficient for non-zero number of weight assignments)
            else if (std::accumulate(currentSnapshot.flux.begin(),currentSnapshot.flux.end(),0) == root * resolved_edges.size()){
                outfluxes.push_back(currentSnapshot.flux);
                lbs.push_back(lower_bounds[i]);
            }
            
        }
    
    }
    
    
    // (4) Start worker
    // (4) Start worker
    std::vector<boost::multiprecision::int128_t> sums = {0,0};
    worker(degrees, genera, nodal_edges, root, graph_stratification, outfluxes, lbs, sums, unsorted_setups);
    
    // (5) return the result
    // (5) return the result
    std::vector<boost::multiprecision::int128_t> result = {sums[0], sums[1]};
    return result;
    
}
