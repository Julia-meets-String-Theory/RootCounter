void distribute_global_sections(const int & N,
                                const std::vector<std::vector<int>> & nodal_edges,
                                const std::vector<int> & genera,
                                const std::vector<int> & maximal_local_sections,
                                std::vector<std::vector<int>> & local_degree_distributions,
                                std::vector<bool> & lower_bounds)
{

    // Compute all partitions with "naive" total sum ranging between N and N + nodal_edges.size()
    std::vector<std::vector<int>> h0_partitions;
    for (int i = 0; i <= nodal_edges.size(); i++){
        comp_partitions(N+i, genera.size(), std::vector<int>(genera.size(),0), maximal_local_sections, h0_partitions);
    }
    
    // Check which of these partitions of h0 can be realized.
    for (int i = 0; i < h0_partitions.size(); i++){
        
				// Find degrees that correspond to the desired local sections.
				
				// Note that there is an ambiguity on how to realize h0 = 0 and h0 = 1 on a g = 1 curve.
				// h0 = 0: Either d < 0 or d = 0.
				// h0 = 1: Either d = 0 or d = 1.
				// Whenever we encounter such a situation, we make one computation for each of these scenarios.
				
				// Create a list that will be filled with the posssible degrees
				std::vector<std::vector<int>> possible_degrees;
				
				// Create a datatype for the snapshotStack
		    struct degree_data{
		        std::vector<int> ds;
		    };
        
        // Create stack and add first (empty) snapshot
        std::stack<degree_data> snapshotStack;
        degree_data currentSnapshot;
        currentSnapshot.ds = {};
        snapshotStack.push(currentSnapshot);
        
        // Run...
        while(!snapshotStack.empty()){
        
            // pick the top snapshot and delete it from the stack
            currentSnapshot= snapshotStack.top();
            snapshotStack.pop();
            
            // any degrees to be set?
            if (currentSnapshot.ds.size() < genera.size()){
                
								// make a copy of the current degrees
								std::vector<int> new_ds = currentSnapshot.ds;
								
								// for which component do we want to find a degree
								int index = new_ds.size();
								
								// if P1, then it is easy to extend by a suitable degree
								if (genera[index] == 0){
										if (h0_partitions[i][index] == 0){
												new_ds.push_back(-1);
										}
										else if (h0_partitions[i][index] > 0){
												new_ds.push_back(h0_partitions[i][index] - 1);
										}
		                degree_data newSnapshot;
		                newSnapshot.ds = new_ds;
		                snapshotStack.push(newSnapshot);
								}
								
								// if elliptic curve, then we must be more careful
								if (genera[index] == 1){
										
										if (h0_partitions[i][index] >= 1){
												new_ds.push_back(h0_partitions[i][index]);
				                degree_data newSnapshot;
				                newSnapshot.ds = new_ds;
				                snapshotStack.push(newSnapshot);
										}
										
										if (h0_partitions[i][index] == 0){
				                std::vector<int> new_ds2 = currentSnapshot.ds;
				                degree_data new_snapshot1, new_snapshot2;
				                new_ds.push_back(0);
				                new_ds2.push_back(-1);
				                new_snapshot1.ds = new_ds;
				                new_snapshot2.ds = new_ds2;
				                snapshotStack.push(new_snapshot1);
				                snapshotStack.push(new_snapshot2);
										}
										
								}
								
            }
            
            // no more degrees to be set, so remember this list of degrees
            else{
                possible_degrees.push_back(currentSnapshot.ds);
            }
            
        }
				
        // Iterate over the possible degree assignments and check which of them truly give the desire h0
        for (int j = 0; j < possible_degrees.size(); j++){
		        bool lb;
		        if (h0_on_nodal_curve(possible_degrees[j], nodal_edges, genera, lb) == N){
		            local_degree_distributions.push_back(possible_degrees[j]);
		            lower_bounds.push_back(lb);
		        }
				}
    
    }
    
}
