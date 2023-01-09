// ####################
// 1. Include libraries
// 1. Include libraries
// ####################

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
#include "../src/ThreadSafe/guards.cpp"
#include "../src/Auxilliary/print_vectors.cpp"
#include "../src/Auxilliary/sum_vectors.cpp"
#include "../src/Auxilliary/handle_input.cpp"
#include "../src/Auxilliary/return_result.cpp"
#include "../src/Graphs/graphs.cpp"
#include "../src/H0/compute_h0_on_tree.cpp"
#include "../src/H0/compute_h0.cpp"
#include "../src/Combinatorics/combinatorics.cpp"
#include "../src/Counter/rootCounter-v3.cpp"
#include "../src/Counter/iterator.cpp"

// Load the test files
#include "Tests/basic_test.cpp"
#include "Tests/QSM6_test.cpp"
#include "Tests/QSM10_test.cpp"

// Optimizations for speedup
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


// ####################
// 2. Execute tests
// 2. Execute tests
// ####################

int main(int argc, char* argv[]){
  test_polytope_128();
}
