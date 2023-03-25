// ####################
// 0. Include libraries
// ####################

#include "include.cpp"


// ########################################
// (1) Tests of h0 computations
// ########################################

void test1(){
  std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
  std::vector<int> degrees = {3,-1,-1,1};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly (test1)");
  assert(bound == true && "The cohomology result should be a lower bound, but is marked as exact (test1)");
}

void test2(){
  std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
  std::vector<int> degrees = {6,-1,-1,-1};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 7 && "Cohomology determined incorrectly (test2)");
  assert(bound == true && "The cohomology result should be a lower bound, but is marked as exact (test2)");
}

void test3(){
  std::vector<std::vector<int>> edges = {{2,3},{3,0}};
  std::vector<int> degrees = {-1,1,-1,4};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly (test3)");
  assert(bound == false && "The cohomology result should be exact, but is marked merely as lower bound (test3)");
}

void test4(){
  std::vector<std::vector<int>> edges = {{2,3},{3,0}};
  std::vector<int> degrees = {-1,-1,5,-1};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 5 && "Cohomology determined incorrectly (test4)");
  assert(bound == false && "The cohomology result should be exact, but is marked merely as lower bound (test4)");
}

void test5(){
  std::vector<std::vector<int>> edges = {};
  std::vector<int> degrees = {0,1,5,2};
  std::vector<int> genera = {0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 12 && "Cohomology determined incorrectly (test5)");
  assert(bound == false && "The cohomology result should be exact, but is marked merely as lower bound (test5)");
}

void test6(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1}};
  std::vector<int> degrees = {0,0};
  std::vector<int> genera = {0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 0 && "Cohomology determined incorrectly for bicircuit (test6)");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact (test6)");
}

void test7(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1}};
  std::vector<int> degrees = {1,0};
  std::vector<int> genera = {0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 1 && "Cohomology determined incorrectly for bicircuit (test7)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test7)");
}

void test8(){
  std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0}};
  std::vector<int> degrees = {1,2,3};
  std::vector<int> genera = {0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 6 && "Cohomology determined incorrectly for tricircuit (test8)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test8)");
}

void test9(){
  std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,0}};
  std::vector<int> degrees = {0,0,0};
  std::vector<int> genera = {0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 0 && "Cohomology determined incorrectly for tricircuit (test9)");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact (test9)");
}

void test10(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2}};
  std::vector<int> degrees = {0,1,-2};
  std::vector<int> genera = {0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 0 && "Cohomology determined incorrectly for tricircuit (test10)");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact (test10)");
}

void test11(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2}};
  std::vector<int> degrees = {0,1,1};
  std::vector<int> genera = {0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 2 && "Cohomology determined incorrectly for tricircuit (test11)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test11)");
}

void test12(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2},{1,3}};
  std::vector<int> degrees = {0,1,-1,-1};
  std::vector<int> genera = {0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 0 && "Cohomology determined incorrectly for tricircuit (test12)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test12)");
}

void test13(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2},{2,3},{3,4}};
  std::vector<int> degrees = {0,1,-1,5,-1};
  std::vector<int> genera = {0,0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly for tricircuit (test13)");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact (test13)");
}

void test14(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2},{1,3},{1,4}};
  std::vector<int> degrees = {0,1,2,-10,-1};
  std::vector<int> genera = {0,0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 2 && "Cohomology determined incorrectly for tricircuit (test14)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test14)");
}

void test15(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{0,1}};
  std::vector<int> degrees = {2,1};
  std::vector<int> genera = {0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 2 && "Cohomology determined incorrectly for bi-triple-circuit (test15)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test15)");
}

void test16(){
  std::vector<std::vector<int>> edges = {{0,2},{0,1},{0,1}};
  std::vector<int> degrees = {0,0,-1};
  std::vector<int> genera = {0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 0 && "Cohomology determined incorrectly for bi-triple-circuit (test16)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test16)");
}

void test17(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2},{1,2},{1,3}};
  std::vector<int> degrees = {0,2,0,0};
  std::vector<int> genera = {0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 1 && "Cohomology determined incorrectly (test17)");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact (test17)");
}

void test18(){
  std::vector<std::vector<int>> edges = {{0,2},{0,2},{1,3},{1,0},{1,0}};
  std::vector<int> degrees = {1,1,1,0};
  std::vector<int> genera = {0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 2 && "Cohomology determined incorrectly for  (test18)");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound (test18)");
}


// ########################################
// (2) Marielle's tests on h0-computation
// ########################################

void Marielle_test1(){
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 2}, {0, 2}, {0, 3}, {2, 3}};
  std::vector<int> degrees = {1, 1, 2, 0};
  std::vector<int> genera = {0, 0, 0, 0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 2 && "Cohomology determined incorrectly for Marielle's test 1");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact for Marielle's test 1");
}

void Marielle_test2(){
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 2}, {0, 2}, {0, 3}, {2, 3}};
  std::vector<int> degrees = {2,1,1,-2};
  std::vector<int> genera = {0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 1 && "Cohomology determined incorrectly for Marielle's test 2");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound for Marielle's test 2");
}

void Marielle_test3(){
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 2}, {0, 2}, {0, 3}, {2, 3}, {3, 4}, {4, 5}};
  std::vector<int> degrees = {2, 2, 2, -2, 1, -2};
  std::vector<int> genera = {0, 0, 0, 0, 0, 0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 3 && "Cohomology determined incorrectly for Marielle's test 3");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound for Marielle's test 3");
}

void Marielle_test4(){
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 2}, {0, 2}, {0, 3}, {2, 3}, {3, 4}, {4, 5}, {0, 5}};
  std::vector<int> degrees = {2, 2, 2, -2, 1, 1};
  std::vector<int> genera = {0, 0, 0, 0, 0, 0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly for Marielle's test 4");
  assert(bound == false && "The cohomology result should be exact, but is marked as lower bound for Marielle's test 4");
}

void Marielle_test5(){
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 2}, {0, 2}, {0, 3}, {2, 3}, {3, 4}, {4, 5}, {0, 5}};
  std::vector<int> degrees = {1, 1, 2, 0, 2, 1};
  std::vector<int> genera = {0, 0, 0, 0, 0, 0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly for Marielle's test 5");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact for Marielle's test 5");
}

void Marielle_test6(){
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {1, 2}, {0, 2}, {0, 3}, {2, 3}, {3, 4}, {4, 5}, {0, 5}};
  std::vector<int> degrees = {2, 1, 2, 1, 0, 0};
  std::vector<int> genera = {0, 0, 0, 0, 0, 0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 3 && "Cohomology determined incorrectly for Marielle's test 6");
  assert(bound == true && "The cohomology result should not be exact, but is marked as exact for Marielle's test 6");
}


// ########################################
// (3) Tests for standarizing graphs
// ########################################

void standardize_test1(){
  std::vector<int> degrees = {0, 0, 0};
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  std::vector<int> new_degrees;
  std::vector<std::vector<int>> new_edges;
  int offset = standardize(degrees, edges, new_degrees, new_edges);
  std::vector<int> expected_new_degrees = {0};
  std::vector<std::vector<int>> expected_new_edges = {{0, 0}};
  int expected_offset = 0;
  assert(offset == expected_offset && "Offset wrongly computed in graph standardization test 1");
  assert(new_degrees == expected_new_degrees && "New degrees wrongly computed in graph standardization test 1");
  assert(new_edges == expected_new_edges && "New degrees wrongly computed in graph standardization test 1");
}

void standardize_test2(){
  std::vector<int> degrees = {0, -1, 0};
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  std::vector<int> new_degrees;
  std::vector<std::vector<int>> new_edges;
  int offset = standardize(degrees, edges, new_degrees, new_edges);
  std::vector<int> expected_new_degrees = {-2};
  std::vector<std::vector<int>> expected_new_edges = {};
  int expected_offset = 0;
  assert(offset == expected_offset && "Offset wrongly computed in graph standardization test 2");
  assert(new_degrees == expected_new_degrees && "New degrees wrongly computed in graph standardization test 2");
  assert(new_edges == expected_new_edges && "New degrees wrongly computed in graph standardization test 2");
}

void standardize_test3(){
  std::vector<int> degrees = {-1, 0, 0};
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  std::vector<int> new_degrees;
  std::vector<std::vector<int>> new_edges;
  int offset = standardize(degrees, edges, new_degrees, new_edges);
  std::vector<int> expected_new_degrees = {-2};
  std::vector<std::vector<int>> expected_new_edges = {};
  int expected_offset = 0;
  assert(offset == expected_offset && "Offset wrongly computed in graph standardization test 3");
  assert(new_degrees == expected_new_degrees && "New degrees wrongly computed in graph standardization test 3");
  assert(new_edges == expected_new_edges && "New degrees wrongly computed in graph standardization test 3");
}

void standardize_test4(){
  std::vector<int> degrees = {2, 0, 0};
  std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  std::vector<int> new_degrees;
  std::vector<std::vector<int>> new_edges;
  int offset = standardize(degrees, edges, new_degrees, new_edges);
  std::vector<int> expected_new_degrees = {0};
  std::vector<std::vector<int>> expected_new_edges = {};
  int expected_offset = 1;
  assert(offset == expected_offset && "Offset wrongly computed in graph standardization test 4");
  assert(new_degrees == expected_new_degrees && "New degrees wrongly computed in graph standardization test 4");
  assert(new_edges == expected_new_edges && "New degrees wrongly computed in graph standardization test 4");
}

void standardize_test5(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2},{1,2},{1,3}};
  std::vector<int> degrees = {0,2,0,0};
  std::vector<int> genera = {0,0,0,0};
  std::vector<int> new_degrees;
  std::vector<std::vector<int>> new_edges;
  int offset = standardize(degrees, edges, new_degrees, new_edges);
  std::vector<int> expected_new_degrees = {2};
  std::vector<std::vector<int>> expected_new_edges = {{0, 0}, {0, 0}};
  int expected_offset = 0;
  assert(offset == expected_offset && "Offset wrongly computed in graph standardization test 5");
  assert(new_degrees == expected_new_degrees && "New degrees wrongly computed in graph standardization test 5");
  assert(new_edges == expected_new_edges && "New degrees wrongly computed in graph standardization test 5");
}

void standardize_test6(){
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2},{2,3},{2,3},{3,0}};
  std::vector<int> degrees = {1,1,1,1};
  std::vector<int> genera = {0,0,0,0};
  std::vector<int> new_degrees;
  std::vector<std::vector<int>> new_edges;
  int offset = standardize(degrees, edges, new_degrees, new_edges);
  std::vector<int> expected_new_degrees = {1,1,1,1};
  std::vector<std::vector<int>> expected_new_edges = {{0,1},{0,1},{1,2},{2,3},{2,3},{3,0}};
  int expected_offset = 0;
  assert(offset == expected_offset && "Offset wrongly computed in  graph standardization test 6");
  assert(new_degrees == expected_new_degrees && "New degrees wrongly computed in graph standardization test 6");
  assert(new_edges == expected_new_edges && "New degrees wrongly computed in graph standardization test 6");
}



// ########################################
// (8) Execute the tests
// ########################################

int main(int argc, char* argv[]){
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
  test14();
  test15();
  test16();
  test17();
  test18();
  Marielle_test1();
  Marielle_test2();
  Marielle_test3();
  Marielle_test4();
  Marielle_test5();
  Marielle_test6();
  standardize_test1();
  standardize_test2();
  standardize_test3();
  standardize_test4();
  standardize_test5();
  standardize_test6();
}
