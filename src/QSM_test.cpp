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



// ####################
// 2. Write tests
// 2. Write tests
// ####################

class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(test1);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  // (2.1) Tests root counts for some QSMs

  void test1(void){
    // (a) Parse input
    std::string input = "4 12 36 12 12 0 1 0 0 6 3 0 2 0 2 3 0 1 1 3 1 2 4 12 8 3 3 0 6 1";
    std::vector<int> unsorted_degrees, unsorted_genera;
    std::vector<std::vector<int>> edges;
    int genus, root, number_threads, h0Min, h0Max, numNodesMin, numNodesMax;
    bool display_details;
    parse_input(input, unsorted_degrees, unsorted_genera, edges, genus, root, number_threads, h0Min, h0Max, numNodesMin, numNodesMax, display_details);
    consistency_check(genus, unsorted_genera, unsorted_degrees, edges, root, h0Min, h0Max, numNodesMin, numNodesMax, number_threads);

    // (b) Count root bundles
    int lower_bound = (int) (std::accumulate(unsorted_degrees.begin(),unsorted_degrees.end(),0)/root) - genus + 1;
    std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
    for (int h0_value = h0Min; h0_value <= h0Max; h0_value++){

        // Are we below the lower bound? -> Answer is trivial
        if (h0_value < lower_bound){
            std::vector<boost::multiprecision::int128_t> result(numNodesMax - numNodesMin + 1,0);
            n_exact.push_back(result);
            n_lower_bound.push_back(result);
            continue;
        }

        // Compute number of root bundles
        std::vector<boost::multiprecision::int128_t> results_exact, results_lower_bound;
        iterator(edges, unsorted_degrees, unsorted_genera, genus, root, h0_value, numNodesMin, numNodesMax, number_threads, results_exact, results_lower_bound);
        n_exact.push_back(results_exact);
        n_lower_bound.push_back(results_lower_bound);

    }

    // (c) Compare with our expectation
    std::vector<boost::multiprecision::int128_t> n_exact_expected = {142560, 47520, 0, 0, 0, 0, 0};
    std::vector<boost::multiprecision::int128_t> n_lower_bound_expected = {0, 47520, 4752, 6336, 0, 0, 144};
    if (n_exact[0] != n_exact_expected){
      std::cout << " Exact number of roots wrong computed.\n";
      for (int i = 0; i < n_exact[0].size(); i++){
        std::cout << "Found: " << n_exact[0][i] << " but expected " << n_exact_expected[i] << "\n";
      }
      exit(1);
    }
    if (n_lower_bound[0] != n_lower_bound_expected){
      std::cout << " Exact number of roots wrong computed.\n";
      for (int i = 0; i < n_lower_bound[0].size(); i++){
        std::cout << "Found: " << n_lower_bound[0][i] << " but expected " << n_lower_bound_expected[i] << "\n";
      }
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
