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

// Include functionality of cppunit test
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

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



// ####################
// 2. Write tests
// 2. Write tests
// ####################

class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(test_polytope_8);
  CPPUNIT_TEST(test_polytope_4);
  CPPUNIT_TEST(test_polytope_134);
  CPPUNIT_TEST(test_polytope_128);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  // (2.1) Tests root counts for some QSMs

  void test_polytope_8(void){
    // (a) Compute the roots
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    count_roots("4 12 36 12 12 0 1 0 0 6 3 0 2 0 2 3 0 1 1 3 1 2 4 12 8 3 3 0 6", n_exact, n_lower_bound);

    // (b) Setup our expectation
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{142560, 47520, 0, 0, 0, 0, 0}};
    std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 47520, 4752, 6336, 0, 0, 144}};

    // (c) Compare computed and expected results
    if (n_exact != n_exact_expected){
      print_vector_of_vector("Found exact results:\n", n_exact);
      print_vector_of_vector("Expected exact results:\n", n_exact_expected);
      exit(1);
    }
    if (n_lower_bound != n_lower_bound_expected){
      print_vector_of_vector("Found lower bounds:\n", n_lower_bound);
      print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
      exit(1);
    }
  }

  void test_polytope_4(void){
    // (a) Compute the roots
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    count_roots("4 12 24 24 12 0 0 0 0 7 3 0 2 0 2 3 1 0 1 3 1 2 1 2 4 12 8 3 3 0 7", n_exact, n_lower_bound);

    // (b) Setup our expectation
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{11110, 7601, 1562, 264, 0, 0, 0, 0}};
    std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 110, 11, 66, 11, 0, 1}};

    // (c) Compare computed and expected results
    if (n_exact != n_exact_expected){
      print_vector_of_vector("Found exact results:\n", n_exact);
      print_vector_of_vector("Expected exact results:\n", n_exact_expected);
      exit(1);
    }
    if (n_lower_bound != n_lower_bound_expected){
      print_vector_of_vector("Found lower bounds:\n", n_lower_bound);
      print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
      exit(1);
    }
  }

  void test_polytope_134(void){
    // (a) Compute the roots
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    count_roots("5 12 24 12 12 12 0 0 0 0 0 8 3 0 4 0 2 3 2 4 1 0 1 3 1 4 1 2 4 12 8 3 3 0 8", n_exact, n_lower_bound);

    // (b) Setup our expectation
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{10010, 8360, 1782, 484, 55, 0, 0, 0, 0}};
    std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 44, 0, 0, 1}};

    // (c) Compare computed and expected results
    if (n_exact != n_exact_expected){
      print_vector_of_vector("Found exact results:\n", n_exact);
      print_vector_of_vector("Expected exact results:\n", n_exact_expected);
      exit(1);
    }
    if (n_lower_bound != n_lower_bound_expected){
      print_vector_of_vector("Found lower bounds:\n", n_lower_bound);
      print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
      exit(1);
    }
  }

  void test_polytope_128(void){
    // (a) Compute the roots
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    count_roots("6 12 12 12 12 12 12 0 0 0 0 0 0 9 3 0 5 0 5 3 0 4 2 3 1 5 2 4 1 4 1 2 4 12 8 3 3 0 9", n_exact, n_lower_bound);

    // (b) Setup our expectation
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{8910, 9240, 1650, 814, 66, 33, 0, 0, 0, 0}};
    std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 22, 0, 0, 1}};

    // (c) Compare computed and expected results
    if (n_exact != n_exact_expected){
      print_vector_of_vector("Found exact results:\n", n_exact);
      print_vector_of_vector("Expected exact results:\n", n_exact_expected);
      exit(1);
    }
    if (n_lower_bound != n_lower_bound_expected){
      print_vector_of_vector("Found lower bounds:\n", n_lower_bound);
      print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
      exit(1);
    }
  }

};




// ####################
// 3. Execute tests
// 3. Execute tests
// ####################

CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main(){
  // Create the event manager and test controller
  CPPUNIT_NS::TestResult controller;

  // Add a listener that colllects test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  // Add a listener that prints dots as test run.
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  // Add the top suite to the test runner
  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  // Return the result
  return result.wasSuccessful() ? 0 : 1;
}
