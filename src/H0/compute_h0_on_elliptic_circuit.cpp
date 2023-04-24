// ##########################
// Consistency check
// ##########################

void elliptic_consistency_check(const std::vector<int>& values, const std::vector<int>& expected_values)
{
    if (values != expected_values){
        throw std::invalid_argument( "Consistency check for h0 computation on elliptic circuit not passed." );
    }
}



// ##########################
// Compute h0 as lower bound
// ##########################

int compute_h0(const std::vector<int>& degrees, const std::vector<int>& genera, const int number_of_edges)
{
    int local_sections = 0;
    for (int i = 0; i < degrees.size(); i++){
        if (genera[i] == 0){
            local_sections += std::max(degrees[i] + 1, 0);
        }
        if (genera[i] == 1){
            local_sections += std::max(degrees[i], 0);
        }
    }
    return std::max(local_sections - number_of_edges, 0);
}



// ##########################
// Betti = 1
// ##########################

int h0_on_connected_elliptic_one_loop(const std::vector<int>& degrees, const std::vector<int>& genera, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    elliptic_consistency_check({(int) edges.size(), (int) degrees.size(), (int) genera.size(), betti_number(edges), self_loops(edges)}, {1, 1, 1, 1, 1});
    if (degrees[0] >= 0 && degrees[0] <= 2){lower_bound = true;} // Window for jumps: VERIFY!
    return compute_h0(degrees, genera, (int) edges.size());
}

int h0_on_connected_elliptic_tapole(const std::vector<int>& degrees, const std::vector<int>& genera, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    elliptic_consistency_check({(int) edges.size(), (int) degrees.size(), (int) genera.size(), betti_number(edges), self_loops(edges)}, {2, 2, 2, 1, 1});
    int elliptic = 0;
    int rational = 1;
    if (genera[1] == 1){
        elliptic = 1;
        rational = 0;
    }
    if (degrees[elliptic] >= 0 && degrees[elliptic] <= 1 && degrees[rational] >= 0 && degrees[rational] <= 1){lower_bound = true;} // Window for jumps: VERIFY!
    return compute_h0(degrees, genera, (int) edges.size());
}


// ##########################
// Betti = 2
// ##########################

int h0_on_connected_elliptic_double_loop(const std::vector<int>& degrees, const std::vector<int>& genera, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    elliptic_consistency_check({(int) edges.size(), (int) degrees.size(), (int) genera.size(), betti_number(edges), self_loops(edges)}, {3, 2, 2, 2, 0});
    int elliptic = 0;
    int rational = 1;
    if (genera[1] == 1){
        elliptic = 1;
        rational = 0;
    }
    if (degrees[elliptic] <= 3 && degrees[elliptic] >= 0 && degrees[rational] <= 1 && degrees[rational] >= 0){lower_bound = true;} // Window for jumps: VERIFY!
    return compute_h0(degrees, genera, (int) edges.size());
}
