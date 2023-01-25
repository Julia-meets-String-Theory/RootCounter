// (1) Compute number of root bundles
// (1) Compute number of root bundles
// (1) Compute number of root bundles

void compute_root_bundles(const std::vector<std::vector<int>> & edges,
                                            const std::vector<int> & degrees,
                                            const std::vector<int> & genera,
                                            const int & root,
                                            const int & h0_value,
                                            const std::vector<int> & positions_no_blowup,
                                            std::vector<boost::multiprecision::int128_t> & sums,
                                            std::vector<std::vector<std::vector<int>>> & unsorted_setups)
{
    
    // Identify nodal_edges and resolved_edges
    std::vector<std::vector<int>> nodal_edges;
    std::vector<std::vector<int>> resolved_edges = edges;
    for (int k = 0; k < positions_no_blowup.size(); k++){
        nodal_edges.push_back(resolved_edges[positions_no_blowup[k]]);
        resolved_edges.erase(resolved_edges.begin()+positions_no_blowup[k]);
    }
    
    // Compute information about the graph formed from the resolved edges, i.e. the one at which we place weights
    std::vector<int> edge_numbers(degrees.size(),0);
    std::vector<std::vector<std::vector<int>>> graph_stratification;
    additional_graph_information(resolved_edges, edge_numbers, graph_stratification);
    
    // Compute number of roots
    std::vector<boost::multiprecision::int128_t> results = root_counter(degrees, genera, resolved_edges, nodal_edges, root, graph_stratification, edge_numbers, h0_value, unsorted_setups);
    
    // Update results
    UpdateCountThreadSafe(sums, results[0], results[1]);
    
}



// (2) Iterate over combinations to compute root bundles
// (2) Iterate over combinations to compute root bundles
// (2) Iterate over combinations to compute root bundles

void runner(const std::vector<std::vector<int>> edges,
                    const std::vector<int> degrees,
                    const std::vector<int> genera,
                    const int root,
                    const int h0_value,
                    const std::vector<std::vector<int>> combinations,
                    std::vector<boost::multiprecision::int128_t> & sums,
                    std::vector<std::vector<std::vector<int>>> & unsorted_setups)
{
    
    for (int i = 0; i < combinations.size(); i++){
        compute_root_bundles(edges, degrees, genera, root, h0_value, combinations[i], sums, unsorted_setups);
    }
    
}



// (3) Iterate over partial blowups
// (3) Iterate over partial blowups
// (3) Iterate over partial blowups

void iterator(const std::vector<std::vector<int>> & edges,
                     const std::vector<int> & degrees,
                     const std::vector<int> & genera,
                     const int & root,
                     const int & h0_value,
                     const int & numNodesMin,
                     const int & numNodesMax,
                     const int & total_number_threads,
                     std::vector<boost::multiprecision::int128_t> & results_exact,
                     std::vector<boost::multiprecision::int128_t> & results_lower_bound,
                     std::vector<std::vector<std::vector<int>>> & unsorted_setups)
{
    
    // declare variable to capture results
    std::vector<boost::multiprecision::int128_t> sums;

    // snapshot stack
    struct SnapShotStruct{
        std::vector<int> combination;
    };
    
    // Iterate over combination of all partial blowups via stack
    for (int i = numNodesMin; i <= numNodesMax; i++){
        
        // initialize vector to capture all combinations
        std::vector<std::vector<int>> combinations;
        
        // set values to zero
        sums = {boost::multiprecision::int128_t(0),boost::multiprecision::int128_t(0)};
        
        // Initialize stack
        std::stack<SnapShotStruct> snapshotStack;
        SnapShotStruct currentSnapshot;
        currentSnapshot.combination = {};
        snapshotStack.push(currentSnapshot);
        
        // Run...
        while(!snapshotStack.empty())
        {
            
            // pick the top snapshot and delete it from the stack
            currentSnapshot= snapshotStack.top();
            snapshotStack.pop();
            
            // more values to be set
            if (currentSnapshot.combination.size() < i){
                
                if (currentSnapshot.combination.empty()){
                    for (int j = edges.size() - 1; j >= 0; j--){
                        SnapShotStruct newSnapshot;
                        newSnapshot.combination = {j};
                        snapshotStack.push(newSnapshot);
                    }
                }
                else{
                    int current_max = currentSnapshot.combination[currentSnapshot.combination.size() - 1];
                    if (currentSnapshot.combination.back() > 0){
                        for (int j = currentSnapshot.combination.back() - 1; j >=0; j--){
                            std::vector<int> new_combination = currentSnapshot.combination;
                            new_combination.push_back(j);
                            SnapShotStruct newSnapshot;
                            newSnapshot.combination = new_combination;
                            snapshotStack.push(newSnapshot);
                        }
                    }
                }
                
            }
            
            // no more values to be set -> compute roots
            if (currentSnapshot.combination.size() == i){
                combinations.push_back(currentSnapshot.combination);
            }
            
        }
        
        // distribute combinations onto threads
        boost::thread_group threadList;
        int package_size = 1;
        int nr_threads = combinations.size();
        if (combinations.size() >= total_number_threads){
            package_size = (int) combinations.size()/total_number_threads;
            nr_threads = total_number_threads;
        }
        for (int i = 0; i < nr_threads; i++){
            if (i < nr_threads - 1){
                std::vector<std::vector<int>> partial_combinations(combinations.begin() + i * package_size, combinations.begin() + (i+1) * package_size);
                boost::thread *t = new boost::thread(runner, edges, degrees, genera, root, h0_value, partial_combinations, boost::ref(sums), boost::ref(unsorted_setups));
                threadList.add_thread(t);
            }
            else{
                std::vector<std::vector<int>> partial_combinations(combinations.begin() + i * package_size, combinations.end());
                boost::thread *t = new boost::thread(runner, edges, degrees, genera, root, h0_value, partial_combinations, boost::ref(sums), boost::ref(unsorted_setups));
                threadList.add_thread(t);
            }
        }
        threadList.join_all();
        
        // remember result from leaving i-nodes
        results_exact.push_back(sums[0]);
        results_lower_bound.push_back(sums[1]);
        
    }

}



// (4) Root counter main method
// (4) Root counter main method
// (4) Root counter main method
void count_roots(const std::string input,
                 const std::string & full_path,
                 const bool & details,
                 std::vector<std::vector<boost::multiprecision::int128_t>> & n_exact,
                 std::vector<std::vector<boost::multiprecision::int128_t>> & n_lower_bound,
                 std::vector<std::vector<std::vector<int>>> & unsorted_setups)
{

    // (1) Parse input
    std::vector<int> degrees, genera;
    std::vector<std::vector<int>> edges;
    int genus, root, number_threads, h0Min, h0Max, numNodesMin, numNodesMax;
    parse_input(input, degrees, genera, edges, genus, root, number_threads, h0Min, h0Max, numNodesMin, numNodesMax);

    // (2) Consistency check
    consistency_check(genus, genera, degrees, edges, root, h0Min, h0Max, numNodesMin, numNodesMax, number_threads);

    // (3) Count root bundles
    std::chrono::steady_clock::time_point before = std::chrono::steady_clock::now();
    int lower_bound = (int) (std::accumulate(degrees.begin(),degrees.end(),0)/root) - genus + 1;
    for (int h0_value = h0Min; h0_value <= h0Max; h0_value++){

        // Are we below the lower bound? -> Answer is trivial
        if (h0_value < lower_bound){
            std::vector<boost::multiprecision::int128_t> result(numNodesMax - numNodesMin + 1,0);
            n_exact.push_back(result);
            n_lower_bound.push_back(result);
            continue;
        }

        // Compute number of root bundles
        std::vector<boost::multiprecision::int128_t> results_exact, results_lower_bound;
        iterator(edges, degrees, genera, root, h0_value, numNodesMin, numNodesMax, number_threads, results_exact, results_lower_bound, unsorted_setups);
        n_exact.push_back(results_exact);
        n_lower_bound.push_back(results_lower_bound);

    }
    std::chrono::steady_clock::time_point after = std::chrono::steady_clock::now();

    // (3) Return the result
    if (details){
        return_result(full_path, n_exact, n_lower_bound, numNodesMax - numNodesMin, numNodesMin, genus, root, h0Min, h0Max, betti_number(edges), before, after, unsorted_setups);
    }

}

void count_roots(const std::string input,
                 std::vector<std::vector<boost::multiprecision::int128_t>> & n_exact,
                 std::vector<std::vector<boost::multiprecision::int128_t>> & n_lower_bound)
{
    std::vector<std::vector<std::vector<int>>> unsorted_setups;
    count_roots(input, "", false, n_exact, n_lower_bound, unsorted_setups);
}
