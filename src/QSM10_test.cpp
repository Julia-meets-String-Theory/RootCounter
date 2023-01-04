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
#include "Auxilliary/sum_vectors.cpp"
#include "Auxilliary/handle_input.cpp"
#include "Auxilliary/return_result.cpp"
#include "Graphs/graphs.cpp"
#include "Graphs/compute_graph_information.cpp"
#include "H0/compute_h0_on_circuit.cpp"
#include "H0/compute_h0_on_tree.cpp"
#include "H0/compute_h0.cpp"
#include "Combinatorics/combinatorics.cpp"
#include "Counter/rootCounter-v3.cpp"
#include "Counter/iterator.cpp"

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
  CPPUNIT_TEST(test_polytope_88);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  // (2.1) Tests root counts for some QSMs

  void test_polytope_88(void){
    // (a) Compute the roots
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    count_roots("5 16 80 32 16 16 0 1 0 0 0 9 4 0 0 3 2 3 2 4 0 1 1 4 1 3 1 2 1 2 6 20 8 3 5 0 9", n_exact, n_lower_bound);

    // (b) Setup our expectation
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
    {{781680888, 163221088, 13270504, 504800, 0, 0, 0, 0, 0, 0},
      {25196800, 5967200, 399200, 0, 0, 0, 0, 0, 0, 0},
      {106800, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
    {{62712, 206886912, 66014696, 9318400, 692000, 24800, 1600, 0, 0, 0},
      {0, 5200000, 1355600, 88800, 0, 0, 0, 0, 0, 0},
      {0, 7200, 0, 0, 0, 0, 0, 0, 0, 0}};

    // (c) Compare computed and expected results
    if (sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)){
        std::cout << "\n\nNot all roots have been found!\n";
        print_vector_of_vector("Found exact results:\n", n_exact);
        print_vector_of_vector("Expected exact results:\n", n_exact_expected);
        print_vector_of_vector("Found lower bounds:\n", n_lower_bound);
        print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
    }
    if (n_exact != n_exact_expected){
      print_vector_of_vector("\n\nFound exact results:\n", n_exact);
      print_vector_of_vector("Expected exact results:\n", n_exact_expected);
      exit(1);
    }
    if (n_lower_bound != n_lower_bound_expected){
      print_vector_of_vector("\n\nFound lower bounds:\n", n_lower_bound);
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
