void parse_input(const std::string & input_string,
                            std::vector<int> & degrees,
                            std::vector<int> & genera,
                            std::vector<std::vector<int>> & edges,
                            int & genus,
                            int & root,
                            int & number_threads,
                            int & h0Min,
                            int & h0Max,
                            int & numNodesMin,
                            int & numNodesMax)
{
    
    // (1) Parse input string into integers
    std::stringstream iss(input_string);
    std::vector<int> input;
    int number;
    while (iss >> number){
        input.push_back(number);
    }
    
    // (2) Read-off vertices, degrees and genera
    int number_vertices = input[0];
    for (int i = 1; i <= number_vertices; i++){
        degrees.push_back(input[i]);
        genera.push_back(input[i + number_vertices]);
    }
    
    // (3) Read-off the edges
    int numberEdges = input[2 * number_vertices + 1];
    for (int i = 0; i < numberEdges; i ++){
        std::vector<int> helper (2);
        int index = 2 + 2 * number_vertices + 2 * i;
        helper[0] = input[index];
        helper[1] = input[index + 1];
        edges.push_back(helper);
    }
    
    // (4) Read-off integer data
    genus = input[2 * number_vertices + 2 + 2 * numberEdges];
    root = input[2 * number_vertices + 2 + 2 * numberEdges + 1];
    number_threads = input[2 * number_vertices + 2 + 2 * numberEdges + 2];
    h0Min = input[2 * number_vertices + 2 + 2 * numberEdges + 3];
    h0Max = input[2 * number_vertices + 2 + 2 * numberEdges + 4];
    numNodesMin = input[2 * number_vertices + 2 + 2 * numberEdges + 5];
    numNodesMax = input[2 * number_vertices + 2 + 2 * numberEdges + 6];
    
}


void consistency_check(const int & genus,
                                      const std::vector<int> & genera,
                                      const std::vector<int> & degrees,
                                      const std::vector<std::vector<int>> & edges,
                                      const int & root,
                                      const int & h0Min,
                                      const int & h0Max,
                                      const int & numNodesMin,
                                      const int & numNodesMax,
                                      const int & number_threads)
{
    assert(*std::min_element(genera.begin(), genera.end()) >= 0 && "Genera must not be negative");
    assert(*std::max_element(genera.begin(), genera.end()) <= 1 && "We currently do not support genera larger than 1");
    assert(genus >= 0 && "Genus must not be negative");
    assert(root >= 2 && "Root must be at least 2");
    assert(h0Min <= h0Max && "h0Min must not be larger than h0Max");
    assert(h0Min >= 0 && "h0Min must not be negative");
    assert(h0Max >= 0 && "h0Max must not be negative");
    assert(numNodesMin >= 0 && "numNodesMin must not be negative");
    assert(numNodesMax <= edges.size() && "numNodesMax must not be larger than the number of edges");
    assert(numNodesMin <= numNodesMax && "numNodesMin must not be larger than numNodesMax");
    assert(number_threads >= 1 && "Number of threads must not be smaller than 1");
    assert(number_threads <= 100 && "Received number of threads larger than 100 - probably this is not good");
    assert(std::accumulate(degrees.begin(),degrees.end(),0) % root == 0 && "Total degree is not divisible by root");
}
