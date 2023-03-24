// ##########################
// Consistency check
// ##########################

void consistency_check(const std::vector<int>& values, const std::vector<int>& expected_values)
{
    if (values != expected_values){
        throw std::invalid_argument( "Consistency check for h0 computation not passed." );
    }
}



// ##########################
// Compute h0 as lower bound
// ##########################

int compute_h0(const std::vector<int>& degrees, const int number_of_edges)
{
    int local_sections = 0;
    for (int i = 0; i < degrees.size(); i++){
        local_sections += std::max(degrees[i] + 1, 0);
    }
    return std::max(local_sections - number_of_edges, 0);
}



// ##########################
// Betti = 1
// ##########################

int h0_on_connected_rational_one_loop(const std::vector<int>& degrees, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    consistency_check({(int) edges.size(), (int) degrees.size(), betti_number(edges), self_loops(edges)}, {1, 1, 1, 1});
    if (degrees[0] == 0){lower_bound = true;} // Canonical bundle
    return compute_h0(degrees, (int) edges.size());
}



// ##########################
// Betti = 2
// ##########################

int h0_on_connected_rational_two_loop(const std::vector<int>& degrees, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    consistency_check({(int) edges.size(), (int) degrees.size(), betti_number(edges), self_loops(edges)}, {2, 1, 2, 2});
    if (degrees[0] >= 0 && degrees[0] <= 2){lower_bound = true;}
    return compute_h0(degrees, (int) edges.size());
}


int h0_on_connected_rational_double_loop(const std::vector<int>& degrees, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    consistency_check({(int) edges.size(), (int) degrees.size(), betti_number(edges), self_loops(edges)}, {3, 2, 2, 0});
    if (degrees[0] >= 0 && degrees[1] >= 0 && degrees[0] <= 1 && degrees[1] <= 1){lower_bound = true;}
    return compute_h0(degrees, (int) edges.size());
}


int h0_on_connected_rational_dumpbell(const std::vector<int>& degrees, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    consistency_check({(int) edges.size(), (int) degrees.size(), betti_number(edges), self_loops(edges)}, {3, 2, 2, 2});
    if (degrees[0] == 0 && degrees[1] >= 0){lower_bound = true;}
    if (degrees[1] == 0 && degrees[0] >= 0){lower_bound = true;}
    if (degrees[0] == 1 && degrees[1] == 1){lower_bound = true;}
    return compute_h0(degrees, (int) edges.size());
}


// ##########################
// Betti = 3
// ##########################

int h0_on_connected_rational_triple_loop(const std::vector<int>& degrees, const std::vector<std::vector<int>>& edges, bool & lower_bound)
{
    consistency_check({(int) edges.size(), (int) degrees.size(), betti_number(edges), self_loops(edges)}, {4, 2, 3, 0});
    if (degrees[0] == 2 && degrees[1] == 2){lower_bound = true;} // Canonical bundle
    return compute_h0(degrees, (int) edges.size());
}
