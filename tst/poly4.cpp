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

// Optimizations for speedup
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


// ####################
// 2. Execute tests
// 2. Execute tests
// ####################

int main(int argc, char* argv[]){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  count_roots("4 12 24 24 12 0 0 0 0 7 3 0 2 0 2 3 1 0 1 3 1 2 1 2 4 12 8 3 3 0 7", n_exact, n_lower_bound);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{11110, 7601, 1562, 264, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 110, 11, 66, 11, 0, 1}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 4 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 4 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 4 failed");
}
