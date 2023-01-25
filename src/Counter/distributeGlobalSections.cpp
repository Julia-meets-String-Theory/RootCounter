void distribute_global_sections(const int & N,
                                const std::vector<std::vector<int>> & nodal_edges,
                                const std::vector<int> & genera,
																const std::vector<int> & maximal_local_sections,
                                std::vector<std::vector<int>> & partitions,
                                std::vector<bool> & lower_bounds)
{
    
		// Find the maximal h0 on each component
		
    // Compute all partitions with "naive" total sum ranging between N and N + nodal_edges.size()
    std::vector<std::vector<int>> h0_partitions;
    for (int i = 0; i <= nodal_edges.size(); i++){
        comp_partitions(N+i, genera.size(), std::vector<int>(genera.size(),0), maximal_local_sections, h0_partitions);
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
