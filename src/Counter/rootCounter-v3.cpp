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
            // no action required -> we can increase the counted numbers
            else{
                
                if (lower_bounds[i]){

                    // Setup for which we only know a lower bound
                    total_unclear = total_unclear + (boost::multiprecision::int128_t) currentSnapshot.mult * number_local_roots;

                    // Remember connected components, which we could not compute h0 for
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
                            std::vector<std::vector<int>> new_unsorted_setup = {gens_of_cc[j], degs_of_cc[j], {h0_of_cc}};
                            for (int k = 0; k < edges_of_cc[j].size(); k++){
                                new_unsorted_setup.push_back(edges_of_cc[j][k]);
                            }
                            //if (betti_number(edges_of_cc[j]) > 0){
                            UpdateUnsortedThreadSafe(unsorted_setups, new_unsorted_setup);
                            //}
                        }
                    }

                }

                else{

                    // Setup for which we perse have not just a lower bound. Still, we want to be extra careful.
                    // So check if there are components with (g = 1, d = 0). If yes, then for one root, we perse only have a lower bound.
                    boost::multiprecision::int128_t number_roots_with_determined_h0 = 1;
                    for (int j = 0; j < genera.size(); j++){
                        if ((genera[j] == 1) && (degrees[j] == outfluxes[i][j])){
                            number_roots_with_determined_h0 = number_roots_with_determined_h0 * (boost::multiprecision::int128_t) (root * root - 1);
                        }
                        if ((genera[j] == 1) && (degrees[j] != outfluxes[i][j])){
                            number_roots_with_determined_h0 = number_roots_with_determined_h0 * (boost::multiprecision::int128_t) (root * root);
                        }
                    }

                    total_clear = total_clear + (boost::multiprecision::int128_t) currentSnapshot.mult * number_roots_with_determined_h0;
                    total_unclear += (boost::multiprecision::int128_t) currentSnapshot.mult * (number_local_roots - number_roots_with_determined_h0);

                }

            }
            
        }
        
    }
    
    // Update result
    UpdateCountThreadSafe(sums, total_clear, total_unclear);
    
}



// Count number of root bundles with prescribed number of sections
std::vector<boost::multiprecision::int128_t> parallel_root_counter(
                                const int & genus,
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
  
    // (1) Partition h0
    // (1) Partition h0
    std::vector<std::vector<int>> partitions;
    std::vector<bool> lower_bounds;
    distribute_global_sections(h0_value, nodal_edges, genera, partitions, lower_bounds);
    
    
    // (2) Find fluxes corresponding to partitions
    // (2) Find fluxes corresponding to partitions
    struct flux_data{
        std::vector<int> flux;
    };
    std::vector<std::vector<int>> outfluxes;
    std::vector<bool> lbs;
    outfluxes.reserve(partitions.size());
    lbs.reserve(partitions.size());
    for (int i = 0; i < partitions.size(); i++){
        
        // create stack and first snapshot
        std::stack<flux_data> snapshotStack;
        flux_data currentSnapshot;
        currentSnapshot.flux = {};
        snapshotStack.push(currentSnapshot);
        
        // Run...
        while(!snapshotStack.empty())
        {
        
            // pick the top snapshot and delete it from the stack
            currentSnapshot= snapshotStack.top();
            snapshotStack.pop();
            
            // any fluxes to be set?
            if (currentSnapshot.flux.size() < degrees.size()){
                
                // determine vertex for which we determine the outflux
                int j = currentSnapshot.flux.size();
                
                // non-trivial h0:
                if (partitions[i][j] > 0){
                    int f = degrees[j] - root * partitions[i][j];
                    if (genera[j] == 0){
                        f += root;
                    }
                    if ((edge_numbers[j] <= f) && (f <= edge_numbers[j] * (root-1)) && ((degrees[j] - f) % root == 0)){
                        std::vector<int> new_flux = currentSnapshot.flux;
                        new_flux.push_back(f);
                        flux_data newSnapshot;
                        newSnapshot.flux = new_flux;
                        snapshotStack.push(newSnapshot);
                    }
                }
                
                // trivial h0:
                if (partitions[i][j] == 0){
                    int min_flux = degrees[j];
                    if (genera[j] == 0){
                        min_flux++;
                    }
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
    
    
    // (3) Start worker
    // (3) Start worker
    std::vector<boost::multiprecision::int128_t> sums = {0,0};
    worker(degrees, genera, nodal_edges, root, graph_stratification, outfluxes, lbs, sums, unsorted_setups);
    
    // (4) return the result
    // (4) return the result
    std::vector<boost::multiprecision::int128_t> result = {sums[0], sums[1]};
    return result;
    
}
