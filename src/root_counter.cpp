// A program to compute the number of root bundles on partial blowups of certain nodal curves

// Include standard functionality
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
#include "ThreadSafe/guards.cpp"
#include "Auxilliary/print_vectors.cpp"
#include "Auxilliary/sum_vectors.cpp"
#include "Auxilliary/handle_input.cpp"
#include "Auxilliary/return_result.cpp"
#include "Graphs/graphs.cpp"
#include "H0/compute_h0_on_circuit.cpp"
#include "H0/compute_h0.cpp"
#include "Combinatorics/combinatorics.cpp"
#include "Counter/distributeGlobalSections.cpp"
#include "Counter/rootCounter-v3.cpp"
#include "Counter/iterator.cpp"

// Optimizations for speedup
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// The main routine
int main(int argc, char* argv[]) {
    if (argc == 2) {
        std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
        std::vector<std::vector<std::vector<int>>> unsorted_setups;
        count_roots(argv[1], argv[0], true, n_exact, n_lower_bound, unsorted_setups);
    }
    else{
        std::cout << "Error - number of arguments must be exactly 1 and not " << argc << "\n";
    }
    return 0;
}
