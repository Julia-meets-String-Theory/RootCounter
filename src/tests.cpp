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
boost::mutex myGuard, myGuard2, myGuard3;

// Determine how the output looks like
bool display_unsorted_setups = true;

// Set up vector to save unsorted setups
std::vector<std::vector<std::vector<int>>> unsorted;

// Include my specialized files
#include "Auxilliary/print_vectors.cpp"
#include "Auxilliary/sum_vectors.cpp"
#include "Auxilliary/handle_input.cpp"
#include "Auxilliary/return_result.cpp"
#include "Graphs/graphs.cpp"
#include "Graphs/compute_graph_information.cpp"
#include "H0/compute_h0_on_tree.cpp"
#include "H0/compute_h0.cpp"
#include "Combinatorics/combinatorics.cpp"
#include "Counter/rootCounter-v3.cpp"
#include "Counter/iterator.cpp"

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
  // Basic tests
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  test12();
  test13();

  // QSM6 tests
  test_polytope_8(argv[0]);
  test_polytope_4();
  test_polytope_134();
  test_polytope_128();

  // QSM10 tests
  test_polytope_88();
}
