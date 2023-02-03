// (1) Auxiliary tools
// (1) Auxiliary tools

bool contains(const std::vector<int> & vec, const int & elem)
{
    return (std::find(vec.begin(), vec.end(), elem) != vec.end());
}

int merge(std::vector<int> & parent, int x)
{
    if (parent[x] == x){
        return x;
    }
    return merge(parent, parent[x]);
}

void find_vertices(std::vector<int>& vertices, const std::vector<std::vector<int>>& input_edges){
    vertices.reserve(2*input_edges.size());
    for (int i = 0; i < input_edges.size(); i++){
        if (!contains(vertices, input_edges[i][0])){
            vertices.push_back(input_edges[i][0]);
        }
        if (!contains(vertices, input_edges[i][1])){
            vertices.push_back(input_edges[i][1]);
        }
    }
}


// (2) Compute additional information about the graph in question
// (2) Compute additional information about the graph in question

void additional_graph_information(
                                  const std::vector<std::vector<int>> & edges,
                                  std::vector<int> & edge_numbers,
                                  std::vector<std::vector<std::vector<int>>> & graph_stratification )
{

    // compute the edge_numbers
    for (int i = 0; i < edges.size(); i++){
        edge_numbers[edges[i][0]]++;
        edge_numbers[edges[i][1]]++;
    }

    // compute the graph_stratification
    bool test = true;
    int index = 0;
    std::vector<std::vector<int>> scan_edges(edges.begin(), edges.end());
    while (test) {

        // determine the vertices connected to the index-th vertex
        std::vector<int> connected_vertices;
        for (int i = 0; i < scan_edges.size(); i++){
            if (scan_edges[i][0] == index && contains(connected_vertices, scan_edges[i][1]) == false){
                connected_vertices.push_back(scan_edges[i][1]);
            }
            if (scan_edges[i][1] == index && contains(connected_vertices, scan_edges[i][0]) == false){
                connected_vertices.push_back(scan_edges[i][0]);
            }
        }

        // determine the number of connecting edges
        std::vector<int> number_of_connecting_edges(connected_vertices.size(),0);
        for (int i = 0; i < connected_vertices.size(); i++){
            for (int j = 0; j < scan_edges.size(); j++){
                if (scan_edges[j][0] == index && scan_edges[j][1] == connected_vertices[i]){
                    number_of_connecting_edges[i]++;
                }
                if (scan_edges[j][1] == index && scan_edges[j][0] == connected_vertices[i]){
                    number_of_connecting_edges[i]++;
                }
            }
        }

        // determine the number of remaining edges for all connected
        std::vector<int> remaining_edges(connected_vertices.size(),0);
        for (int i = 0; i < connected_vertices.size(); i++){
            for (int j = 0; j < scan_edges.size(); j++){
                if (scan_edges[j][0] != index && scan_edges[j][1] == connected_vertices[i]){
                    remaining_edges[i]++;
                }
                if (scan_edges[j][1] != index && scan_edges[j][0] == connected_vertices[i]){
                    remaining_edges[i]++;
                }
            }
        }

        // add data to graph_stratification
        graph_stratification.push_back({connected_vertices, number_of_connecting_edges, remaining_edges});

        // compute new list of edges
        std::vector<std::vector<int>> new_edges;
        new_edges.reserve(scan_edges.size());
        for (int i = 0; i < scan_edges.size(); i++){
            if (scan_edges[i][0] != index && scan_edges[i][1] != index){
                new_edges.push_back(scan_edges[i]);
            }
        }

        // check if we are done: are there no remaining edges?
        if (new_edges.size() == 0){
            // yes -> end while loop
            test = false;
        }
        else{
            // not yet done -> prepare for next iteration
            index++;
            scan_edges = new_edges;
        }

    }

}


// (3) Find the number of connected components
// (3) Find the number of connected components

int number_connected_components(const std::vector<std::vector<int>>& input_edges)
{
    
    // (1) Find all vertices (avoiding duplicated) and sort them in ascending order
    std::vector<int> vertices;
    find_vertices(vertices, input_edges);
    
    // (2) Construct vertex_correspondence: input vertex names (e.g. "0, 2, 5, 6, ...") -> "0, 1, 2, 3, ..."
    std::map<int, int> vertex_correspondence;
    for (int i = 0; i < vertices.size(); i++){
        vertex_correspondence.insert(std::pair<int, int>(vertices[i], i));
    }
    
    // (3) Form list of edges with internal/new vertex indices (-> can be easily processed below)
    std::vector<std::vector<int>> edges;
    edges.reserve(input_edges.size());
    for (int i = 0; i < input_edges.size(); i++){
        edges.push_back({vertex_correspondence[input_edges[i][0]], vertex_correspondence[input_edges[i][1]]});
    }
    
    // (4) Count number of connected components
    int c = 0;
    std::vector<int> parent(vertices.size());
    std::iota(std::begin(parent), std::end(parent), 0);
    for (int i = 0; i < edges.size(); i++){
        parent[merge(parent, edges[i][0])] = merge(parent, edges[i][1]);
    }
    for (int i = 0; i < vertices.size(); i++) {
        c += (parent[i] == i);
    }
    
    // return betti number
    return c;
    
}


// (4) Compute the first Betti number
// (4) Compute the first Betti number

int betti_number(const std::vector<std::vector<int>>& input_edges)
{

    // Handle degenerate case
    if (input_edges.size() == 0){
        return 0;
    }

    // Otherwise just do it...
    std::vector<int> vertices;
    find_vertices(vertices, input_edges);
    return input_edges.size() + number_connected_components(input_edges) - vertices.size();

}


// (5) Find the connected components of a graph
// (5) Find the connected components of a graph

void find_connected_components( const std::vector<std::vector<int>> & input_edges,
                                const std::vector<int> & degrees,
                                const std::vector<int> & genera,
                                std::vector<std::vector<std::vector<int>>> & edges_of_cc,
                                std::vector<std::vector<int>> & degrees_of_cc,
                                std::vector<std::vector<int>> & genera_of_cc)
{
    
    // (1) Compute the vertices of the connected components
    std::vector<std::vector<int>> vertices_of_cc;
    std::vector<int> parent(degrees.size());
    std::iota(std::begin(parent), std::end(parent), 0);
    for (int i = 0; i < input_edges.size(); i++){
        parent[merge(parent, input_edges[i][0])] = merge(parent, input_edges[i][1]);
    }
    for (int i = 0; i < degrees.size(); i++) {
        parent[i] = merge(parent, parent[i]);
    }
    std::map<int, std::vector<int>> m;
    for (int i = 0; i < degrees.size(); i++) {
        m[parent[i]].push_back(i);
    }
    for (auto it = m.begin(); it != m.end(); it++){
        vertices_of_cc.push_back(it->second);
    }
    
    // (2) Initialize the lists
    edges_of_cc.resize(vertices_of_cc.size());
    degrees_of_cc.resize(vertices_of_cc.size());
    genera_of_cc.resize(vertices_of_cc.size());
    
    // (3) Fill the lists with the details of the connected components, that is of their edges, degrees and genera
    for (int i = 0; i < vertices_of_cc.size(); i++){
        
        // (3.1) Make dictionary: current vertex names (e.g. "0, 2, 5, 6, ...") -> "0, 1, 2, 3, ..."
        std::map<int, int> vertex_correspondence;
        for (int j = 0; j < vertices_of_cc[i].size(); j++){
            vertex_correspondence.insert(std::pair<int, int>(vertices_of_cc[i][j], j));
        }
        
        // (3.2) Construct edge list of this connected component
        for (int j = 0; j < input_edges.size(); j++){
            if (std::count(vertices_of_cc[i].begin(), vertices_of_cc[i].end(), input_edges[j][0])){
                edges_of_cc[i].push_back({vertex_correspondence[input_edges[j][0]], vertex_correspondence[input_edges[j][1]]});
            }
        }
        
        // (3.3) Construct degree and genera list
        for (int j = 0; j < vertices_of_cc[i].size(); j++){
            degrees_of_cc[i].push_back(degrees[vertices_of_cc[i][j]]);
            genera_of_cc[i].push_back(genera[vertices_of_cc[i][j]]);
        }
        
    }
    
}


// (6) Find all external leafs of a graph
// (6) Find all external leafs of a graph
void find_external_leafs(const std::vector<std::vector<int>> & edges,
                         std::vector<int> & leafs)
{
    
    // Degenerate case: no edges
    if (edges.size() == 0){
        leafs.clear();
        return;
    }
    
    // Find the vertices
    std::vector<int> vertices;
    find_vertices(vertices, edges);

    // Iterate over all vertices
    for (int i = 0; i < vertices.size(); i++){
        int count_for_component_i = 0;
        for (int j = 0; j < edges.size(); j++){
            if ((edges[j][0] == i) || (edges[j][1] == i)){
                count_for_component_i++;
            }
        }
        if (count_for_component_i == 1){
            leafs.push_back(i);
        }
    }
    
    // In principle, all components could be leafs. In this case, by convention we leave the component 0.
    if (leafs.size() == vertices.size()){
        leafs.erase(std::find(leafs.begin(), leafs.end(), 0));
    }
}


// (7) Remove all external leafs of a graph with degrees
// (7) Remove all external leafs of a graph with degrees
void simplify_by_removing_external_leafs(const std::vector<int> & degrees,
                                         const std::vector<std::vector<int>> & edges,
                                         std::vector<int> & new_degrees,
                                         std::vector<std::vector<int>> & new_edges)
{
    
    // Find all leafs
    std::vector<int> leafs;
    find_external_leafs(edges, leafs);
    
    // Degenerate case
    if (leafs.size() == 0){
        new_degrees = degrees;
        new_edges = edges;
        return;
    }
    
    // Save input information in internal variables that we can manipulate as we simplify the graph
    std::vector<int> internal_degrees = degrees;
    std::vector<std::vector<int>> internal_edges = edges;
    
    // Simplify until no leafs are left
    while (leafs.size() > 0){
        
        // Empty new_degrees and new_edges
        new_degrees.clear();
        new_edges.clear();
        
        // To remove the leafs, make a dictionary from the old component names to the new ones
        std::map<int, int> dictionary;
        int counter = 0;
        for (int i = 0; i < internal_degrees.size(); i++){
            if (std::find(leafs.begin(), leafs.end(), i) == leafs.end()){
                dictionary.insert(std::pair<int, int>(i, counter));
                counter++;
            }
        }
        
        // Make list with the new edges
        for (int i = 0; i < internal_edges.size(); i++){
            if ((std::find(leafs.begin(), leafs.end(), internal_edges[i][0]) == leafs.end()) && (std::find(leafs.begin(), leafs.end(), internal_edges[i][1]) == leafs.end())){
                new_edges.push_back({dictionary[internal_edges[i][0]], dictionary[internal_edges[i][1]]});
            }
        }
        
        // Copy the old degrees for the remaining vertices
        for (int i = 0; i < internal_degrees.size() - leafs.size(); i++){
            new_degrees.push_back(0);
        }
        for (int i = 0; i < internal_degrees.size(); i++){
            if (std::find(leafs.begin(), leafs.end(), i) == leafs.end()){
                new_degrees[dictionary[i]] = internal_degrees[i];
            }
        }
        
        // Adjust the degrees of the remaining vertices to reflect the leafs that we removed
        for(int i = 0; i < internal_degrees.size(); i++){
            
            // Only degrees of vertices that are not leafs are to be recorded
            if (std::find(leafs.begin(), leafs.end(), i) == leafs.end()){
                
                // Iterate over all edges, to find the leafs attached to i
                for (int j = 0; j < internal_edges.size(); j++){
                    
                    if ((internal_edges[j][0] == i) && (std::find(leafs.begin(), leafs.end(), internal_edges[j][1]) != leafs.end())){
                        
                        if (internal_degrees[internal_edges[j][1]] < 0){
                            new_degrees[dictionary[i]]--;
                        }
                        if (internal_degrees[internal_edges[j][1]] >= 0){
                            new_degrees[dictionary[i]] += internal_degrees[internal_edges[j][1]];
                        }
                    }
                    
                    if ((internal_edges[j][1] == i) && (std::find(leafs.begin(), leafs.end(), internal_edges[j][0]) != leafs.end())){
                        
                        if (internal_degrees[internal_edges[j][0]] < 0){
                            new_degrees[dictionary[i]]--;
                        }
                        if (internal_degrees[internal_edges[j][0]] >= 0){
                            new_degrees[dictionary[i]] += internal_degrees[internal_edges[j][0]];
                        }
                    }
                
                }
            
            }
        
        }
        
        // Copy new_degrees and new_edges to internal_degrees and internal_edges
        internal_degrees = new_degrees;
        internal_edges = new_edges;
        
        // Compute the leafs anew
        leafs.clear();
        find_external_leafs(internal_edges, leafs);
        
    }
    
}


// (8) Find an internal leafs of a graph
// (8) Find an internal leafs of a graph
int find_an_internal_leaf(const std::vector<std::vector<int>> & edges)
{
    
    // Degenerate case: no edges
    if (edges.size() == 0){
        return -1;
    }
    
    // Find the vertices
    std::vector<int> vertices;
    find_vertices(vertices, edges);

    // Iterate over all vertices
    for (int i = 0; i < vertices.size(); i++){
        int count_for_component_i = 0;
        std::vector<int> connectors;
        for (int j = 0; j < edges.size(); j++){
            if (edges[j][0] == i){
                count_for_component_i++;
                connectors.push_back(edges[j][1]);
            }
            
            if (edges[j][1] == i){
                count_for_component_i++;
                connectors.push_back(edges[j][0]);
            }
        }
        if (count_for_component_i == 2){
            // remove duplicates from connectors
            std::sort(connectors.begin(), connectors.end()); 
            auto last = std::unique(connectors.begin(), connectors.end());
            connectors.erase(last, connectors.end());
            
            // If i is connnected to exactly two distint components and none of them is i itself, then we have found an internal leaf
            if ((connectors.size() == 2) && (std::find(connectors.begin(), connectors.end(), i) == connectors.end())){
                return i;
            }
        }
    }
    
    // Default is -1, which means: "There are no internal leafs/trees"
    return -1;
}


// (9) Remove all internal leafs of a graph with degrees
// (9) Remove all internal leafs of a graph with degrees
void simplify_by_removing_internal_leafs(const std::vector<int> & degrees,
                                         const std::vector<std::vector<int>> & edges,
                                         std::vector<int> & new_degrees,
                                         std::vector<std::vector<int>> & new_edges)
{
    
    // Find an internal leaf
    int internal_leaf = find_an_internal_leaf(edges);
    
    // Degenerate case
    if (internal_leaf == -1){
        new_degrees = degrees;
        new_edges = edges;
        return;
    }
    
    // Save input information in internal variables that we can manipulate as we simplify the graph
    std::vector<int> internal_degrees = degrees;
    std::vector<std::vector<int>> internal_edges = edges;
    
    // Simplify until no internal leafs are left
    while (internal_leaf != -1){
        
        // Empty new_degrees and new_edges
        new_degrees.clear();
        new_edges.clear();
        
        // To remove the internal leaf, make a dictionary from the old component names to the new ones
        std::map<int, int> dictionary;
        int counter = 0;
        for (int i = 0; i < internal_degrees.size(); i++){
            if (i != internal_leaf){
                dictionary.insert(std::pair<int, int>(i, counter));
                counter++;
            }
        }
        
        // Make list with the new edges
        for (int i = 0; i < internal_edges.size(); i++){
            if (internal_edges[i][0] != internal_leaf && internal_edges[i][1] != internal_leaf){
                new_edges.push_back({dictionary[internal_edges[i][0]], dictionary[internal_edges[i][1]]});
            }
        }
        
        // Find the two vertices that connected to the leaf in question
        std::vector<int> connectors;
        for (int i = 0; i < internal_edges.size(); i++){
            if (internal_edges[i][0] == internal_leaf){
                connectors.push_back(internal_edges[i][1]);
            }
            if (internal_edges[i][1] == internal_leaf){
                connectors.push_back(internal_edges[i][0]);
            }
        }
        
        // Add the edge that connects in place of the internal leaf
        new_edges.push_back({dictionary[connectors[0]], dictionary[connectors[1]]});
        
        // Copy the old degrees for the remaining vertices
        for (int i = 0; i < internal_degrees.size() - 1; i++){
            new_degrees.push_back(0);
        }
        for (int i = 0; i < internal_degrees.size(); i++){
            if (i != internal_leaf){
                new_degrees[dictionary[i]] = internal_degrees[i];
            }
        }
        
        // Adjust the degree on one connector
        if (internal_degrees[internal_leaf] < 0){
            new_degrees[dictionary[connectors[0]]]--;
        }
        if (internal_degrees[internal_leaf] >= 0){
            new_degrees[dictionary[connectors[0]]] += internal_degrees[internal_leaf];
        }
        
        // Copy new_degrees and new_edges to internal_degrees and internal_edges
        internal_degrees = new_degrees;
        internal_edges = new_edges;
        
        // Compute an internal leaf anew
        internal_leaf = find_an_internal_leaf(internal_edges);
        
    }
    
}

// (10) Simplify a graph with degrees
// (10) Simplify of a graph with degrees
void simplify(const std::vector<int> & degrees,
              const std::vector<std::vector<int>> & edges,
              std::vector<int> & new_degrees,
              std::vector<std::vector<int>> & new_edges)
{
    std::vector<int> internal_degrees;
    std::vector<std::vector<int>> internal_edges;
    simplify_by_removing_external_leafs(degrees, edges, internal_degrees, internal_edges);
    simplify_by_removing_internal_leafs(internal_degrees, internal_edges, new_degrees, new_edges);
}
