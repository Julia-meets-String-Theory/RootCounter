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
            return h0_on_rational_tree(degrees, nodal_edges);
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
void h0_on_nodal_curve_new(const std::vector<int>& degrees,
                        const std::vector<std::vector<int>>& nodal_edges,
                        const std::vector<int> & genera,
                        int & h0,
                        bool & lower_bound)
{
    
    // (0) Assumption: We can compute everything exactly
    lower_bound = false;
    
    // (1) Compute the connected components
    std::vector<std::vector<std::vector<int>>> edges_of_cc;
    std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
    find_connected_components(nodal_edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
    
    // (2) Compute h0 by iterating over the connected components
    h0 = 0;
    for (int i = 0; i < edges_of_cc.size(); i++){
        h0 += h0_on_connected_nodal_curve(degs_of_cc[i], edges_of_cc[i], gens_of_cc[i], lower_bound);
    }
    
}




// Compute/estimate via lower bound h0 on nodal curve
// Compute/estimate via lower bound h0 on nodal curve
// Compute/estimate via lower bound h0 on nodal curve

void h0_on_nodal_curve_old(const std::vector<int>& degrees,
                        const std::vector<std::vector<int>>& nodal_edges,
                        const std::vector<int> & genera,
                        int & h0,
                        bool & lower_bound)
{
    
    // (0) Initial assumption: We can compute the exact number of global sections
    lower_bound = false;
    
    
    // (1) Find compoents with nodes and add h0's from components without nodes
    std::vector<int> components_with_nodes;
    h0 = 0;
    for (int i = 0; i < degrees.size(); i++){
        bool test = false; // component i has no nodes attached to it
        for (int j = 0; j < nodal_edges.size(); j++){
            if ((nodal_edges[j][0] == i) || (nodal_edges[j][1] == i)){
                
                // Check for degenerate case: Is a g = 1 attached to node? If so, provide only lower bound.
                if (genera[i] == 1){
                    lower_bound = true;
                    h0 = 0;
                    for (int k = 0; k < degrees.size(); k++){
                        if ((degrees[k] >= 0)&&(genera[k] == 0)){
                            h0 += degrees[k]+1;
                        }
                        if ((degrees[k] >= 0)&&(genera[k] == 1)){
                            h0 += degrees[k];
                        }
                    }
                    if (h0 >= nodal_edges.size()){
                        h0 -= nodal_edges.size();
                    }
                    else{
                        h0 = 0;
                    }
                    return;
                }

                // Remember this component and off to the next
                components_with_nodes.push_back(i);
                test = true;
                break;
                
            }
        }
        if (!test && (degrees[i] >= 0) && (genera[i] == 0)){
            h0 += degrees[i]+1;
        }
        if (!test && (degrees[i] >= 0) && (genera[i] == 1)){
            // We only compute a lower bound. So we assume that d = 0 on elliptic curve implies h0 = 0.
            h0 += degrees[i];
        }
    }

    
    // (3) Degenerate case: no nodes
    if (components_with_nodes.size() == 0){
        return;
    }
    
    
    // (4) Compute all connected components
    std::vector<std::vector<std::vector<int>>> edges_of_cc;
    std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
    find_connected_components_old(nodal_edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
    
    
    // (5) Iterate over the connected components
    //h0 = 0;
    for (int i = 0; i < edges_of_cc.size(); i++){
        
        // tree-like case
        if (betti_number(edges_of_cc[i]) == 0){
            h0 += h0_on_rational_tree(degs_of_cc[i], edges_of_cc[i]);
        }
        
        // beyond what we can currently handle
        else{
            lower_bound = true;
            int number_nodes = edges_of_cc[i].size();
            int local_sections = 0;
            for (int j = 0; j < degs_of_cc[i].size(); j++){
                if (degs_of_cc[i][j] >= 0){
                    local_sections += degs_of_cc[i][j] - gens_of_cc[i][j] + 1;
                }
            }
            if (local_sections >= number_nodes){
                h0 += local_sections - number_nodes;
            }
        }
        
    }
    
    return;
    
}

void h0_on_nodal_curve(const std::vector<int>& degrees,
                        const std::vector<std::vector<int>>& nodal_edges,
                        const std::vector<int> & genera,
                        int & h0,
                        bool & lower_bound)
{
    
    int h0_old, h0_new;
    bool lb_old, lb_new;
    h0_on_nodal_curve_new(degrees, nodal_edges, genera, h0_new, lb_new);
    h0_on_nodal_curve_old(degrees, nodal_edges, genera, h0_old, lb_old);
    
    // Compare
    /*if ((h0_old > h0_new) && (lb_old == true) && (lb_new == true)){
        
        std::cout << "\n\nNew lower bound lower than old lower bound!\n\n";
        print_vector("Degrees ", degrees);
        print_vector("Genera ", genera);
        print_vector_of_vector("Edges \n", nodal_edges);
        std::cout << "H0 new: " << std::to_string(h0_new) << "\n";
        std::cout << "H0 old: " << std::to_string(h0_old) << "\n";
        std::cout << "Lb new: true\n";
        std::cout << "Lb old: true\n";
        
    }*/
    
    if ((h0_old != h0_new) && (lb_old == false) && (lb_new == false)){
        
        std::cout << "\n\nDifferent exact results!\n\n";
        print_vector("Degrees ", degrees);
        print_vector("Genera ", genera);
        print_vector_of_vector("Edges \n", nodal_edges);
        std::cout << "H0 new: " << std::to_string(h0_new) << "\n";
        std::cout << "H0 old: " << std::to_string(h0_old) << "\n";
        std::cout << "Lb new: false\n";
        std::cout << "Lb old: false\n";
    
    }
    
    /*if (lb_old != lb_new){
        
        std::cout << "\n\nDisagreement on lower bound or exact result!\n\n";
        print_vector("Degrees ", degrees);
        print_vector("Genera ", genera);
        print_vector_of_vector("Edges \n", nodal_edges);
        std::cout << "H0 new: " << std::to_string(h0_new) << "\n";
        std::cout << "H0 old: " << std::to_string(h0_old) << "\n";
        if (lb_new){
            std::cout << "Lb new: true\n";
        }
        else{
            std::cout << "Lb new: false\n";
        }
        if (lb_old){
            std::cout << "Lb old: true\n";
        }
        else{
            std::cout << "Lb old: false\n";
        }
        
    }*/
    
    h0 = h0_new;
    lower_bound = lb_new;
    
}
