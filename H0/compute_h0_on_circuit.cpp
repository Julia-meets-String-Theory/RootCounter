int h0_on_rational_bi_circuit(const std::vector<int>& degrees,
                              const std::vector<std::vector<int>>& nodal_edges,
                              bool & lower_bound)
{
            
    // Count local sections
    int local_sections = 0;
    for (int i = 0; i < degrees.size(); i++){
        if (degrees[i] >= 0){
            local_sections += degrees[i] + 1;
        }
    }
    
    // Estimate number of conditions
    int conditions = 0;
    for (int j = 0; j < nodal_edges.size(); j++){
        if ((degrees[nodal_edges[j][0]] >= 0) || (degrees[nodal_edges[j][1]] >= 0)){
            conditions++;
        }
    }
    
    // Merely a lower bound?
    if (degrees[0] == 0 && degrees[1] == 0){
        lower_bound = true;
    }
    
    // Return result for h0
    if (local_sections >= conditions){
        return local_sections - conditions;
    }
    else{
        return 0;
    }
    
}
/*
int h0_on_rational_tri_circuit(const std::vector<int>& degrees,
                               const std::vector<std::vector<int>>& nodal_edges)
{

            
            
            
            
            
            if (connected_components[i].size() == 3){
                
                // Slightly more involved case, as 3 components can form b1 in different ways
                // -> Need to tell those configurations apart.
                
                // find out if there is an amputated component
                std::vector<int> copy_of_components(connected_components[i]);
                std::vector<int> amputated_components;
                std::vector<int> connected_to;
                for (int j = 0; j < connected_components[i].size(); j++){
                    int count_for_component_j = 0;
                    for (int k = 0; k < edges_of_connected_components[i].size(); k++){
                        if (edges_of_connected_components[i][k][0] == connected_components[i][j]){
                            count_for_component_j++;
                        }
                        if (edges_of_connected_components[i][k][1] == connected_components[i][j]){
                            count_for_component_j++;
                        }
                        if (count_for_component_j > 1){
                            break;
                        }
                    }

                    if (count_for_component_j == 1){
                        amputated_components.push_back(connected_components[i][j]);
                        //copy_of_components.erase(copy_of_components.begin()+j);
                        for (int k = 0; k < edges_of_connected_components[i].size(); k++){
                            int connector;
                            if (edges_of_connected_components[i][k][0] == connected_components[i][j]){
                                connector = edges_of_connected_components[i][k][1];
                                connected_to.push_back(connector);
                            }
                            if (edges_of_connected_components[i][k][1] == connected_components[i][j]){
                                connector = edges_of_connected_components[i][k][0];
                                connected_to.push_back(connector);
                            }
                            int pos = std::distance(copy_of_components.begin(),std::find(copy_of_components.begin(), copy_of_components.end(), connector));
                            //copy_of_components.erase(copy_of_components.begin()+pos);
                        }
                    }
                }
                
                
                
                // Case 1: Circuit of 3 components
                int d1,d2,d3;
                if (amputated_components.size() == 0){
                    
                    d1 = degree_correspondence[connected_components[i][0]];
                    d2 = degree_correspondence[connected_components[i][1]];
                    d3 = degree_correspondence[connected_components[i][2]];
                    
                    if (d1 == 0 && d2 == 0 && d3 == 0){
                        lower_bound = true;
                    }
                }
                
                
                // Case 2: Circuit of 2 components and one amputated component
                else if (amputated_components.size() == 1){
                    
                    // find out to what components the amputated component is not connected to
                    // TODO This is now special for 3 compoennts, i.e. at most one amputated component, one connected and
                    // TODO one component which the amputated component is not connected to
                    std::vector<int> not_connected_to;
                    for (int j = 0; j < connected_components[i].size(); j++){
                        if ((connected_components[i][j] != amputated_components[0])
                            && (connected_components[i][j] != connected_to[0])){
                            not_connected_to.push_back(connected_components[i][j]);
                            break;
                        }
                    }
                    //std::vector<int> not_connected_to(copy_of_components);
                    
                    // Consistency check
                    if (amputated_components.size() != 1 || connected_to.size() != 1 || not_connected_to.size() != 1){
                        //throw std::invalid_argument("\nPartition of circuit into amputated, connected and not connected went wrong.\n");
                        std::cout << "\nProblem:\n";
                        print_vector("Amputated:", amputated_components);
                        print_vector("Connected:", connected_to);
                        print_vector("Not connected:", not_connected_to);
                        std::cout << "\n\n";
                    }
                    
                    d1 = degree_correspondence[not_connected_to[0]];
                    d2 = degree_correspondence[connected_to[0]];
                    d3 = degree_correspondence[amputated_components[0]];
                    
                    if (d1 == 0 && d2 == 1 && d3 < 0){
                        lower_bound = true;
                    }
                }
            }
            
        }
*/
