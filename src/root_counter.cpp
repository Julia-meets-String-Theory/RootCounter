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
boost::mutex myGuard, myGuard2, myGuard3;

// Determine how the output looks like
bool display_more_details = false;
bool display_unsorted_setups = true;

// Set up vector to save unsorted setups
std::vector<std::vector<std::vector<int>>> unsorted;

// Include my specialized files
#include "Auxilliary/print_vectors.cpp"
#include "Auxilliary/handle_input.cpp"
#include "Auxilliary/return_result.cpp"
#include "Graphs/graphs.cpp"
#include "Graphs/compute_graph_information.cpp"
#include "H0/compute_h0_on_circuit.cpp"
#include "H0/compute_h0_on_tree.cpp"
#include "H0/compute_h0.cpp"
#include "Combinatorics/combinatorics.cpp"
#include "RootCounter/rootCounter-v3.cpp"
#include "RootCounter/iterator.cpp"

// Optimizations for speedup
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// The main routine
int main(int argc, char* argv[]) {
    
    // (1) Parse the input
    if (argc != 2) {
        std::cout << "Error - number of arguments must be exactly 1 and not " << argc << "\n";
        std::cout << argv[ 0 ] << "\n";
        return 0;
    }
    std::vector<int> unsorted_degrees, unsorted_genera;
    std::vector<std::vector<int>> edges;
    int genus, root, number_threads, h0Min, h0Max, numNodesMin, numNodesMax;
    bool display_details;
    parse_input(argv[1], unsorted_degrees, unsorted_genera, edges, genus, root, number_threads, h0Min, h0Max, numNodesMin, numNodesMax, display_details);
    
    // (2) Count rooot bundles
    count_roots(argv[0], genus, unsorted_genera, unsorted_degrees, edges, root, h0Min, h0Max, numNodesMin, numNodesMax, number_threads, display_details);
    return 0;
    
}
