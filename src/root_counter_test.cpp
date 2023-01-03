// ####################
// 1. Include libraries
// 1. Include libraries
// ####################

// Include standard functionality
#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>

// Include functionality of boost
#include <boost/multiprecision/cpp_int.hpp>

// Include functionality of cppunit test
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

// Include specialized code that will be tested here
#include "Auxilliary/print_vectors.cpp"
#include "Graphs/graphs.cpp"
#include "Graphs/compute_graph_information.cpp"
#include "H0/compute_h0_on_circuit.cpp"
#include "H0/compute_h0_on_tree.cpp"
#include "H0/compute_h0.cpp"
#include "Combinatorics/combinatorics.cpp"



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
  CPPUNIT_TEST(test4);
  CPPUNIT_TEST(test5);
  CPPUNIT_TEST(test6);
  CPPUNIT_TEST(test7);
  CPPUNIT_TEST(test8);
  CPPUNIT_TEST(test9);
  CPPUNIT_TEST(test10);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:

  // (2.1) Tests of graph functionality

  void test1(void){
    std::vector<std::vector<int>> edges = {{0,1},{0,2},{3,4},{3,4},{5,6},{6,7}};
    if (3 != number_connected_components(edges)){
      std::cout << " Wrong number of connected components found.\n";
      std::cout << "Found " << std::to_string(number_connected_components(edges)) << " connected components but should be 3.\n";
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test2(void){
    std::vector<std::vector<int>> edges = {{3,4},{3,4}};
    if (1 != betti_number(edges)){
      std::cout << " Wrong Betti number found.\n";
      std::cout << "Found " << std::to_string(number_connected_components(edges)) << " but should be 1.\n";
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test3(void){
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
      std::cout << " Wrong connected components computed.\n";
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

  // (2.2) Tests of h0 computations

  void test4(void){
    std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
    std::vector<int> degrees = {3,-1,-1,1};
    std::vector<int> genera = {0,1,0,0};
    int h0;
    bool bound;
    h0_on_nodal_curve_new(degrees, edges, genera, h0, bound);
    if (h0 != 4 || bound != true){
      std::cout << " Wrong cohomology computation.\n";
      if (h0 != 4){
        std::cout << "Found " << std::to_string(h0) << " but should be 4.\n";
      }
      if (bound != true){
        std::cout << "Found lower bound false but should be true.\n";
      }
      print_vector("Degrees ", degrees);
      print_vector("Genera ", genera);
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test5(void){
    std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
    std::vector<int> degrees = {6,-1,-1,-1};
    std::vector<int> genera = {0,1,0,0};
    int h0;
    bool bound;
    h0_on_nodal_curve_new(degrees, edges, genera, h0, bound);
    if (h0 != 7 || bound != true){
      std::cout << " Wrong cohomology computation.\n";
      if (h0 != 7){
        std::cout << "Found " << std::to_string(h0) << " but should be 7.\n";
      }
      if (bound != true){
        std::cout << "Found lower bound false but should be true.\n";
      }
      print_vector("Degrees ", degrees);
      print_vector("Genera ", genera);
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test6(void){
    std::vector<std::vector<int>> edges = {{2,3},{3,0}};
    std::vector<int> degrees = {-1,1,-1,4};
    std::vector<int> genera = {0,1,0,0};
    int h0;
    bool bound;
    h0_on_nodal_curve_new(degrees, edges, genera, h0, bound);
    if (h0 != 4 || bound != false){
      std::cout << " Wrong cohomology computation.\n";
      if (h0 != 4){
        std::cout << "Found " << std::to_string(h0) << " but should be 4.\n";
      }
      if (bound != false){
        std::cout << "Found lower bound true but should be false.\n";
      }
      print_vector("Degrees ", degrees);
      print_vector("Genera ", genera);
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  void test7(void){
    std::vector<std::vector<int>> edges = {{2,3},{3,0}};
    std::vector<int> degrees = {-1,-1,5,-1};
    std::vector<int> genera = {0,1,0,0};
    int h0;
    bool bound;
    h0_on_nodal_curve_new(degrees, edges, genera, h0, bound);
    if (h0 != 5 || bound != false){
      std::cout << " Wrong cohomology computation.\n";
      if (h0 != 5){
        std::cout << "Found " << std::to_string(h0) << " but should be 5.\n";
      }
      if (bound != false){
        std::cout << "Found lower bound true but should be false.\n";
      }
      print_vector("Degrees ", degrees);
      print_vector("Genera ", genera);
      print_vector_of_vector("Edges\n", edges);
      exit(1);
    }
  }

  // (2.3) Tests of combinatoric computations

  void test8(void){
    std::vector<std::vector<int>> partitions;
    comp_partitions(3,2,{0,0},{3,3}, partitions);
    if (partitions.size() != 4){
      std::cout << " Wrong partitions computed.\n";
      std::cout << "Goal: Partition N = 3 into a sum of 2 integers n1, n2 with 0 <= n1 <= 3 and 0 <= n2 <= 3.\n";
      print_vector_of_vector("Found partitions\n", partitions);
      exit(1);
    }
  }

  void test9(void){
    std::vector<std::vector<int>> nodal_edges = {{0,1},{1,2}};
    std::vector<int> genera = {0,0,0};
    std::vector<std::vector<int>> partitions;
    comp_partitions_with_nodes(2,nodal_edges,genera,partitions);
    if (partitions.size() != 15){
      std::cout << " Wrong partitions computed.\n";
      print_vector_of_vector("Goal: Partition h0 = 2 on a rational tree with edges\n", nodal_edges);
      print_vector_of_vector("Found the following partitions\n", partitions);
      exit(1);
    }
  }

  void test10(void){
    boost::multiprecision::int128_t np = number_partitions(10,3,5);
    if (np != 6){
      std::cout << " Wrong partitions computed.\n";
      std::cout << "Goal: Partition N = 10 into 3 integers w1, w2, w3 with 1 <= w1, w2, w3 <= 4.\n";
      std::cout << "Found " << np << " partitions, but should be 6.\n";
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
