int h0_on_rational_bi_circuit(const std::vector<int>& degrees,
                              const std::vector<std::vector<int>>& edges,
							  bool & lower_bound)
{
    
    // Consistency check: 2 edges and exactly 2 degrees
    if (edges.size() != 2 || degrees.size() != 2){
        throw std::invalid_argument( "RationalBiCircuit received a number of edges or degrees that is different from 2." );
        return -10;
    }
    
    // Consistency check 2: We want that both edges begin and end at different curves
    if (edges[0][0] == edges[0][1] || edges[1][0] == edges[1][1]){
        throw std::invalid_argument( "RationalBiCircuit expects all edges to begin and end on different curves." );
        return -10;
    }
    
    // Handle special case: We MIGHT be looking at the canonical bundle, so can only compute a lower bound.
    if (degrees[0] == 0 && degrees[1] == 0){
        lower_bound = true;
        return 0;
    }
    
    // Find global h0
    int local_sections = std::max(degrees[0] + 1, 0) + std::max(degrees[1] + 1, 0);
    return std::max(local_sections - 2, 0);
    
}
/*
int h0_on_rational_tri_circuit(const std::vector<int>& degrees,
                               const std::vector<std::vector<int>>& edges)
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
