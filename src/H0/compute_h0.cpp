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
        
        if (betti_number(edges) == 1 && edges.size() == 2 && edges[0][0] != edges[0][1] && edges[1][0] != edges[1][1]){
            return h0_on_rational_bi_circuit(degrees, edges, lower_bound);
        }
        
        if (betti_number(edges) == 2){
            
            if (edges.size() == 3 && edges[0][0] != edges[0][1] && edges[1][0] != edges[1][1] && edges[2][0] != edges[2][1]){
                return h0_on_rational_bi_triple_circuit(degrees, edges, lower_bound);
            }
            
            if (edges.size() == 4 && edges[0][0] != edges[0][1] && edges[1][0] != edges[1][1] && edges[2][0] != edges[2][1] && edges[3][0] != edges[3][1]){
                return h0_on_rational_bi_loop(degrees, edges, lower_bound);
            }
            
        }
        
        if (betti_number(edges) == 3){
            
            if (edges.size() == 4 && edges[0][0] != edges[0][1] && edges[1][0] != edges[1][1] && edges[2][0] != edges[2][1] && edges[3][0] != edges[3][1]){
                return h0_on_rational_bi_quadruple_circuit(degrees, edges, lower_bound);
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
        
        // Are we looking at a nodal curve with rational components only?
        // If so, standardize it and iterate over the resulting connected components.
        if (*std::max_element(std::begin(gens_of_cc[i]), std::end(gens_of_cc[i])) == 0){
            
            // Standardize the graph
            std::vector<int> new_degrees;
            std::vector<std::vector<int>> new_edges;
            int offset = standardize(degs_of_cc[i], edges_of_cc[i], new_degrees, new_edges);
            
            // Identify the connected components
            std::vector<int> new_genera(new_degrees.size(), 0);
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
