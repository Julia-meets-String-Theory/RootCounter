// This method computes the exact number of global section on a CONNECTED nodal curve.
// Should this not be possible (e.g. because of high genus components), then a lower bound is computed instead.
int h0_on_standardized_connected_nodal_curve(const std::vector<int>& degrees,
                                             const std::vector<std::vector<int>>& edges,
                                             const std::vector<int> & genera,
                                             bool & lower_bound)
{
    
    // (1) No edge, so must be a single component that is not self-connected.
    if (edges.size() == 0){
        if (degrees[0] == 0 && genera[0] == 1){
            lower_bound = true;
        }
        return std::max(degrees[0] - genera[0] + 1, 0);
    }
    
    // (2) Only rational components and at least one edge
    if (edges.size() > 0 && (*std::max_element(std::begin(genera), std::end(genera)) == 0)){
        
        if (betti_number(edges) == 1){
            
            if (degrees.size() == 1 && self_loops(edges) == 1){
                return h0_on_connected_rational_one_loop(degrees, edges, lower_bound);
            }
        }
        
        if (betti_number(edges) == 2){
            
            if (degrees.size() == 1 && self_loops(edges) == 2){
                return h0_on_connected_rational_two_loop(degrees, edges, lower_bound);
            }
            
            if (degrees.size() == 2 && self_loops(edges) == 0){
                return h0_on_connected_rational_double_loop(degrees, edges, lower_bound);
            }
            
            if (degrees.size() == 2 && self_loops(edges) == 2){
                return h0_on_connected_rational_dumpbell(degrees, edges, lower_bound);
            }
            
        }
        
        if (betti_number(edges) == 3){
            
            if (degrees.size() == 2 && self_loops(edges) == 0){
                return h0_on_connected_rational_triple_loop(degrees, edges, lower_bound);
            }
            
        }
        
        
    }
    
    // (3) Lower bound if all else fails
    lower_bound = true;
    int local_sections = 0;
    for (int i = 0; i < degrees.size(); i++){
        if (degrees[i] >= 0){
            local_sections += degrees[i] - genera[i] + 1;
        }
    }
    return std::max(local_sections - (int) edges.size(), 0);
    
}


// This method computes the exact number of global section on a nodal curve.
// Should this not be possible (e.g. because of high genus components), then a lower bound is computed instead.
// This method will modify the referenced boolean lower_bound to be true if we merely computed a lower bound.
// Otherwise, it will be set to be false.
int h0_on_nodal_curve(const std::vector<int>& degrees,
                        const std::vector<std::vector<int>>& edges,
                        const std::vector<int> & genera,
                        bool & lower_bound)
{
    
    // (1) Assumption: We can compute everything exactly
    lower_bound = false;
    
    // (2) Find the connected components
    std::vector<std::vector<std::vector<int>>> edges_of_cc;
    std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
    find_connected_components(edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
    
    // (3) Compute h0 by iterating over the connected components
    int h0 = 0;
    for (int i = 0; i < edges_of_cc.size(); i++){
        
        // How many rational and elliptic curves?
        int number_rational = 0;
        int number_elliptic = 0;
        for (int j = 0; j < gens_of_cc[i].size(); j++){
            if (gens_of_cc[i][j] == 0){
                number_rational++;
            }
            if (gens_of_cc[i][j] == 1){
                number_elliptic++;
            }
        }
        
        // Are we either looking at a nodal curve that we can simplify to compute h0 more accurately?
        bool can_simplify_curve = false;
        if (number_rational == gens_of_cc[i].size()){
            can_simplify_curve = true;
        }
        if ((betti_number(edges_of_cc[i]) == 0) && (number_rational == gens_of_cc[i].size() - 1) && (number_elliptic == 1)){
            can_simplify_curve = true;
        }
        
        // Simplify the curve to work out h0 more accurately.
        if (can_simplify_curve){
            
            // Standardize the graph
            std::vector<int> new_degrees, new_genera;
            std::vector<std::vector<int>> new_edges;
            int offset = standardize(degs_of_cc[i], edges_of_cc[i], gens_of_cc[i], new_degrees, new_edges, new_genera);
            
            // Identify the connected components
            std::vector<std::vector<std::vector<int>>> standardized_edges_of_cc;
            std::vector<std::vector<int>> standardized_degs_of_cc, standardized_gens_of_cc;
            find_connected_components(new_edges, new_degrees, new_genera, standardized_edges_of_cc, standardized_degs_of_cc, standardized_gens_of_cc);
            
            // Iterate over the standardized connected components
            h0 += offset;
            for (int j = 0; j < standardized_edges_of_cc.size(); j++){
                h0 += h0_on_standardized_connected_nodal_curve(standardized_degs_of_cc[j], standardized_edges_of_cc[j], standardized_gens_of_cc[j], lower_bound);
            }
            
        }
        else{
            h0 += h0_on_standardized_connected_nodal_curve(degs_of_cc[i], edges_of_cc[i], gens_of_cc[i], lower_bound);
        }
    }
    return h0;

}
