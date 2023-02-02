int h0_on_rational_bi_circuit(const std::vector<int>& degrees,
                              const std::vector<std::vector<int>>& edges,
							  bool & lower_bound)
{
    
    // This function assumes that the graph formed by the provided edges is connected. However, this is not checked!
    
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
    
    // Consistency check 3: We expect b1(graph) = 1
    if (betti_number(edges) != 1){
        throw std::invalid_argument( "RationalBiCircuit received a graph with first Betti number different from 1." );
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


int h0_on_rational_bi_triple_circuit(const std::vector<int>& degrees,
                                     const std::vector<std::vector<int>>& edges,
							         bool & lower_bound)
{
    
    // This function assumes that the graph formed by the provided edges is connected. However, this is not checked!
    
    // Consistency check: Exactly 3 edges
    if (edges.size() != 3){
        throw std::invalid_argument( "RationalBiTripleCircuit received a number of edges that is different from 3." );
        return -10;
    }
    
    // Consistency check 2: Exactly 2 degrees
    if (degrees.size() != 2){
        throw std::invalid_argument( "RationalBiTripleCircuit received a number of degrees that is different from 2." );
        return -10;
    }
    
    // Consistency check 2: We want that all edges begin and end at different curves
    if (edges[0][0] == edges[0][1] || edges[1][0] == edges[1][1] || edges[2][0] == edges[2][1]){
        throw std::invalid_argument( "RationalBiTripleCircuit expects all edges to begin and end on different curves." );
        return -10;
    }
    
    // Consistency check 3: We expect b1(graph) = 2
    if (betti_number(edges) != 2){
        throw std::invalid_argument( "RationalBiTripleCircuit received a graph with first Betti number different from 2." );
        return -10;
    }
    
    // Handle special case: We MIGHT be looking at the canonical bundle, so can only compute a lower bound.
    if (degrees[0] == 1 && degrees[1] == 1){
        lower_bound = true;
        return 1;
    }
    
    // Find global h0
    int local_sections = std::max(degrees[0] + 1, 0) + std::max(degrees[1] + 1, 0);
    return std::max(local_sections - 3, 0);
    
}


int h0_on_rational_tri_circuit(const std::vector<int>& degrees,
                               const std::vector<std::vector<int>>& edges,
                               bool & lower_bound)
{
    
    // This function assumes that the graph formed by the provided edges is connected. However, this is not checked!
    
    // Consistency check: 3 edges and exactly 3 degrees
    if (edges.size() != 3 || degrees.size() != 3){
        throw std::invalid_argument( "RationalTriCircuit received a number of edges or degrees that is different from 3." );
        return -10;
    }
    
    // Consistency check 2: We want that all edges begin and end at different curves
    if (edges[0][0] == edges[0][1] || edges[1][0] == edges[1][1] || edges[2][0] == edges[2][1]){
        throw std::invalid_argument( "RationalTriCircuit expects all edges to begin and end on different curves." );
        return -10;
    }
    
    // Consistency check 3: We expect b1(graph) = 1
    if (betti_number(edges) != 1){
        throw std::invalid_argument( "RationalTriCircuit received a graph with first Betti number different from 1." );
        return -10;
    }
    
    // We need to tell two distinct setups apart. The difference is one amputated component. So find out if there is an amputated component/leaf.
    int amputated_component = -1;
    int connector = -1;
    for (int j = 0; j < degrees.size(); j++){
        int count_for_component_j = 0;
        for (int k = 0; k < edges.size(); k++){
            if (edges[k][0] == j || edges[k][1] == j){
                count_for_component_j++;
            }
            if (count_for_component_j > 1){
                break;
            }
        }
        if (count_for_component_j == 1){
            amputated_component = j;
            for (int k = 0; k < edges.size(); k++){
                if (edges[k][0] == j){
                    connector = edges[k][1];
                }
                if (edges[k][1] == j){
                    connector = edges[k][0];
                }
            }
            break;
        }
    }
    
    // Case 1: No amputated component, i.e. circuit/loop formed from 3 components.
    if (amputated_component == -1){
        
        // Special case: We MIGHT be looking at the canonical bundle.
        if (degrees[0] == 0 && degrees[1] == 0 && degrees[2] == 0){
            lower_bound = true;
            return 0;
        }
        
        // Compute global H0
        int local_sections = std::max(degrees[0] + 1, 0) + std::max(degrees[1] + 1, 0) + std::max(degrees[2] + 1, 0);
        return std::max(local_sections - 3, 0);
        
    }
    // Case 2: One amputated component, i.e. circuit/loop formed from 2 components and one leaf.
    else{
        
        // Extract the degrees
        int d0 = degrees[amputated_component];
        int d1 = degrees[connector];
        std::vector<int> indices = {0,1,2};
        indices.erase(find(indices.begin(), indices.end(), connector));
        indices.erase(find(indices.begin(), indices.end(), amputated_component));
        int d2 = degrees[indices[0]];
        
        // Reduce to bi-circuit
        if (d0 < 0){
            return h0_on_rational_bi_circuit({d1-1,d2},{{0,1},{0,1}}, lower_bound);
        }
        else{
            return h0_on_rational_bi_circuit({d1+d0,d2},{{0,1},{0,1}}, lower_bound);
        }
        
    }
    
}