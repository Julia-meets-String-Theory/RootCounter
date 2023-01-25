// (1) Compute partitions of an integer N into a sum of n integers with specified minima and maxima.
// (1) Compute partitions of an integer N into a sum of n integers with specified minima and maxima.
// (1) Compute partitions of an integer N into a sum of n integers with specified minima and maxima.

// Task: Given an integer N, partition it into a sum of n integers w_1,...,w_n. The k-th integer w_n can have values minima[k] <= k <= maxima[k].

void comp_partitions(
        const int & N,
        const int & n,
        const std::vector<int> & minima,
        const std::vector<int> & maxima,
        std::vector<std::vector<int>> & partitions){
    
    // Only one value to set?
    if(n == 1) {
        if (minima[0] <= N and N <= maxima[0]){
            partitions.push_back({N});
        }
        return;
    }
    
    // Create stack
    struct SnapShotStruct {
        std::vector<int> p;
    };
    std::stack<SnapShotStruct> snapshotStack;
    
    // Add first snapshot
    SnapShotStruct currentSnapshot;
    currentSnapshot.p = {};
    snapshotStack.push(currentSnapshot);
    
    // Run...
    while(!snapshotStack.empty())
    {
        
        // pick the top snapshot and delete it from the stack
        currentSnapshot= snapshotStack.top();
        snapshotStack.pop();
        
        // current sum
        int current_sum = std::accumulate(currentSnapshot.p.begin(), currentSnapshot.p.end(), 0);

        // position at which we add
        int pos = currentSnapshot.p.size();            
        
        // there are at least two more values to be set
        if (pos < n-1){
        
            // Compute min and max for this placement
            int max = maxima[pos];
            if (N - current_sum < max ){
                max = N - current_sum;
            }
            
            // Iterate over these values
            for (int i = minima[pos]; i <= max; i++){
                std::vector<int> new_partition = currentSnapshot.p;
                new_partition.push_back(i);
                SnapShotStruct newSnapshot;
                newSnapshot.p = new_partition;
                snapshotStack.push(newSnapshot);
            }
            
        }
        
        // only one more value to be set
        else if ((pos == n-1) && (minima[pos] <= N - current_sum) && (N - current_sum <= maxima[pos])){
            std::vector<int> new_partition = currentSnapshot.p;
            new_partition.push_back(N - current_sum);
            partitions.push_back(new_partition);
        }
        
    }
    
}


// (2) Compute partitions of an integer N including possible boundary conditions.
// (2) Compute partitions of an integer N including possible boundary conditions.
// (2) Compute partitions of an integer N including possible boundary conditions.

// This works for any tree-like blowup and is used for this particular purpose.
void distribute_global_sections(const int & N,
                                const std::vector<std::vector<int>> & nodal_edges,
                                const std::vector<int> & genera,
                                std::vector<std::vector<int>> & partitions,
                                std::vector<bool> & lower_bounds)
{
    
    // Compute all partitions with "naive" total sum ranging between N and N + nodal_edges.size()
    std::vector<std::vector<int>> h0_partitions;
    for (int i = 0; i <= nodal_edges.size(); i++){
        comp_partitions(N+i, genera.size(), std::vector<int>(genera.size(),0), std::vector<int>(genera.size(),N+i), h0_partitions);
    }
    
    // Check which of these partitions of h0 can be realized.
    for (int i = 0; i < h0_partitions.size(); i++){
        
        // Find SOME degrees corresponding to the local h0.
        // The only ambiguity is for h0 = 0. In all these cases, the sections are identically trivial. And so, it does not matter which degree we choose, it will always lead to the same h0.
        // However, it has an impact on whether or not we can compute h0 with full confidence, or whether we only get a lower bound.
        // We mark cases, in which there is a doubt that we can compute h0 correctly with lower_bound = true.
        std::vector<int> degrees;
        for (int j = 0; j < genera.size(); j++){
            if (h0_partitions[i][j] > 0){
                if (genera[j] == 0){
                    degrees.push_back(h0_partitions[i][j]-1);
                }
                if (genera[j] == 1){
                    degrees.push_back(h0_partitions[i][j]);
                }
            }
            else{
                if (genera[j] == 0){
                    degrees.push_back(-1);
                }
                if (genera[j] == 1){
                    degrees.push_back(0);
                }
            }
        }

        // Check if this results at h0
        bool lb;
        if (h0_on_nodal_curve(degrees, nodal_edges, genera, lb) == N){
            partitions.push_back(h0_partitions[i]);
            lower_bounds.push_back(lb);
        }
    
    }
    
}


// (3) Compute number of partitions of an integer f.
// (3) Compute number of partitions of an integer f.
// (3) Compute number of partitions of an integer f.

// Task: Compute the number of partitions of an integer f into n integers w1, ... ,wn with values 1 <= w1, ..., wn < r.
// Careful: THE ORDER DOES MATTER! I.e. 3 = 0 + 1 + 2 is not considered the same as 3 = 2 + 1 + 0!

boost::multiprecision::int128_t partition_helper(const int & f, const int & n, const int & r, std::vector<std::vector<boost::multiprecision::int128_t>> & memory)
{
    
    // initialize the counter
    boost::multiprecision::int128_t count = (boost::multiprecision::int128_t) 0;
    
    // Valid value for f and n?
    if ((f < 1) || (n < 1)){
        return 0;
    }
    
    // Only one value to set? Check if we have a partition
    if(n == 1){
        if ((1<= f)&&(f<r)){
            return (boost::multiprecision::int128_t) 1;
        }
        else{
            return (boost::multiprecision::int128_t) 0;
        }
    }
    
    // Pick values and make recursive call
    for (int i = 1; i < r; i++){
        if (1 <= f-i){
            if (memory[f-i][n-1] = -1){
                memory[f-i-1][n-1-1] = partition_helper(f - i, n-1, r, memory);
            }
            count = count + memory[f-i-1][n-1-1];
        }
    }
    
    // return final result
    return count;    
}

boost::multiprecision::int128_t number_partitions(
        const int & f,
        const int & n,
        const int & r)
{
    
    // We recursively compute number_partitions(f-i, n-1, r).
    // This means the first argument can range between 1 and f.
    // The second argument can range between 1 and n.
    // -> At most, we have to perform f * n computations.
    // Cache them to speed up the computation!
    
    // Initialize memory and start computation
    std::vector<std::vector<boost::multiprecision::int128_t>> memory(f, std::vector<boost::multiprecision::int128_t>(n, (boost::multiprecision::int128_t) -1)); 
    return partition_helper(f, n, r, memory);
    
}
