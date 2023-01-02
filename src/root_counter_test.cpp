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

// Include functionality of cppunit test
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
bool display_more_details = false;
bool display_unsorted_setups = true;
std::vector<std::vector<std::vector<int>>> unsorted;
// Include specialized code that will be tested here
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
  CPPUNIT_TEST(test2);
  CPPUNIT_TEST(test3);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  void test1(void) {
    std::vector<std::vector<int>> edges = {{0,1},{0,2},{3,4},{3,4},{5,6},{6,7}};
    if (3 != number_connected_components(edges)){
      std::cout << "Wrong number of connected components found.\n";
      std::cout << "Found " << std::to_string(number_connected_components(edges)) << " connected components but should be 3.\n";
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test2(void) {
    std::vector<std::vector<int>> edges = {{3,4},{3,4}};
    if (1 != betti_number(edges)){
      std::cout << "Wrong Betti number found.\n";
      std::cout << "Found " << std::to_string(number_connected_components(edges)) << " but should  be 1.\n";
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test3(void) {
    std::vector<std::vector<int>> edges = {{1,2},{3,4},{2,5},{6,4},{7,8},{0,9}};
    std::vector<int> degrees = {-2,3,4,-1,0,5,7,8,-9,9};
    std::vector<int> genera = {0,1,0,1,0,1,0,1,0,1};
    std::vector<std::vector<std::vector<int>>> edges_of_cc;
    std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
    find_connected_components(edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
    std::vector<std::vector<std::vector<int>>> expected_edges_of_cc = {{{0,1},{2,1}},{{0,1},{1,2}},{{0,1}},{{0,1}}};
    std::vector<std::vector<int>> expected_degs_of_cc = {{-1,0,7},{3,4,5},{8,-9},{-2,9}};
    std::vector<std::vector<int>> expected_gens_of_cc = {{1,0,0},{1,0,1},{1,0},{0,1}};
    if ((edges_of_cc != expected_edges_of_cc) || (degs_of_cc != expected_degs_of_cc) || (gens_of_cc != expected_gens_of_cc)){
      std::cout << "Wrong connected components computed.\n";
      std::cout << "Found the following connected components\n\n";
      for (int i = 0; i < edges_of_cc.size(); i++){
        std::cout << "Component " << std::to_string(i) << "\n";
        print_vector_of_vector("Edges:\n", edges_of_cc[i]);
        print_vector("Degrees: ", degs_of_cc[i]);
        print_vector("Genera: ", gens_of_cc[i]);
        std::cout << "\n";
      }
      std::cout << "-------------------------------------------";
      std::cout << "Expected the following connected components\n\n";
      for (int i = 0; i < expected_edges_of_cc.size(); i++){
        std::cout << "Component " << std::to_string(i) << "\n";
        print_vector_of_vector("Edges:\n", expected_edges_of_cc[i]);
        print_vector("Degrees: ", expected_degs_of_cc[i]);
        print_vector("Genera: ", expected_gens_of_cc[i]);
        std::cout << "\n";
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
