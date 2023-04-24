#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <fstream>
#include <iostream>
#include <mutex>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <vector>

// Include functionality of boost
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

// Include my specialized files
#include "../src/ThreadSafe/guards.cpp"
#include "../src/Auxilliary/print_vectors.cpp"
#include "../src/Auxilliary/sum_vectors.cpp"
#include "../src/Auxilliary/handle_input.cpp"
#include "../src/Auxilliary/return_result.cpp"
#include "../src/Graphs/graphs.cpp"
#include "../src/H0/compute_h0_on_elliptic_circuit.cpp"
#include "../src/H0/compute_h0_on_circuit.cpp"
#include "../src/H0/compute_h0.cpp"
#include "../src/Combinatorics/combinatorics.cpp"
#include "../src/Counter/distributeGlobalSections.cpp"
#include "../src/Counter/rootCounter-v3.cpp"
#include "../src/Counter/iterator.cpp"

// Optimizations for speedup
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// This method checks the results for the QSM root counting
int conduct_test(const std::string & input,
                 const std::string & path,
                 const std::vector<std::vector<boost::multiprecision::int128_t>> & n_exact_expected,
                 const std::vector<std::vector<boost::multiprecision::int128_t>> & n_lower_bound_expected,
                 const boost::multiprecision::int128_t & total)
{
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    std::vector<std::vector<std::vector<int>>> unsorted_setups;
    count_roots(input, path, true, n_exact, n_lower_bound, unsorted_setups);
    if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
        return -1;
    }
    return 0;
}