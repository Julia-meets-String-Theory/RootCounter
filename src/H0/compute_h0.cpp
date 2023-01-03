// This method computes the exact number of global section on a CONNECTED nodal curve.
// Should this not be possible (e.g. because of high genus components), then a lower bound is computed instead.
int h0_on_connected_nodal_curve(const std::vector<int>& degrees,
                                 const std::vector<std::vector<int>>& nodal_edges,
                                 const std::vector<int> & genera,
                                 bool & lower_bound)
{
    
    // (1) A single component that is not self-connected
    if (degrees.size() == 1 && nodal_edges.size() == 0){
        if (degrees[0] >= 0){
            return degrees[0] - genera[0] + 1;
        }
    }
    
    // (2) At least two components
    if (degrees.size() > 1){
    
        // (2.1) Is there a non-rational component?
        bool rational = (*std::max_element(std::begin(genera), std::end(genera)) == 0);
        
        // (2.2) Compute h0 for a rational tree
        if (betti_number(nodal_edges) == 0 && rational){
            return h0_on_connected_rational_tree(degrees, nodal_edges);
        }
        
        // (2.3) Compute h0 for a rational bi-circuit
        /*if (betti_number(nodal_edges) == 1 && rational && degrees.size() == 2){
            return h0_on_rational_bi_circuit(degrees, nodal_edges, lower_bound);
        }*/
        
        // (2.4) For all remaining cases, compute a lower bound
        lower_bound = true;
        int number_nodes = nodal_edges.size();
        int local_sections = 0;
        for (int i = 0; i < degrees.size(); i++){
            if (degrees[i] >= 0){
                local_sections += degrees[i] - genera[i] + 1;
            }
        }
        if (local_sections >= number_nodes){
            return local_sections - number_nodes;
        }
        
    }
    
    // Standard return value if all else fails
    return 0;
    
}


// This method computes the exact number of global section on a nodal curve.
// Should this not be possible (e.g. because of high genus components), then a lower bound is computed instead.
// This method will modify the referenced boolean lower_bound to be true if we merely computed a lower bound.
// Otherwise, it will be set to be false.
int h0_on_nodal_curve(const std::vector<int>& degrees,
                        const std::vector<std::vector<int>>& nodal_edges,
                        const std::vector<int> & genera,
                        bool & lower_bound)
{
    
    // (0) Assumption: We can compute everything exactly
    lower_bound = false;
    
    // (1) Compute the connected components
    std::vector<std::vector<std::vector<int>>> edges_of_cc;
    std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
    find_connected_components(nodal_edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
    
    // (2) Compute h0 by iterating over the connected components
    int h0 = 0;
    for (int i = 0; i < edges_of_cc.size(); i++){
        h0 += h0_on_connected_nodal_curve(degs_of_cc[i], edges_of_cc[i], gens_of_cc[i], lower_bound);
    }
    return h0;

}
