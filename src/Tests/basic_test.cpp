// ########################################
// (1) Tests of graph functionality
// ########################################

void test1(){
  std::vector<std::vector<int>> edges = {{0,1},{0,2},{3,4},{3,4},{5,6},{6,7}};
  assert(number_connected_components(edges) == 3 && "Connected components computed incorrectly");
}

void test2(){
  std::vector<std::vector<int>> edges = {{3,4},{3,4}};
  std::vector<std::vector<int>> edges2 = {};
  assert(betti_number(edges) == 1 && "Betti number computed incorrectly");
  assert(betti_number(edges2) == 0 && "Betti number computed incorrectly");
}

void test3(){
  std::vector<std::vector<int>> edges = {{1,2},{3,4},{2,5},{6,4},{7,8},{0,9}};
  std::vector<int> degrees = {-2,3,4,-1,0,5,7,8,-9,9};
  std::vector<int> genera = {0,1,0,1,0,1,0,1,0,1};
  std::vector<std::vector<std::vector<int>>> edges_of_cc;
  std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
  find_connected_components(edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
  std::vector<std::vector<std::vector<int>>> expected_edges_of_cc = {{{0,1},{2,1}},{{0,1},{1,2}},{{0,1}},{{0,1}}};
  std::vector<std::vector<int>> expected_degs_of_cc = {{-1,0,7},{3,4,5},{8,-9},{-2,9}};
  std::vector<std::vector<int>> expected_gens_of_cc = {{1,0,0},{1,0,1},{1,0},{0,1}};
  assert(edges_of_cc == expected_edges_of_cc && "Edges of connected components computed incorrectly");
  assert(degs_of_cc == expected_degs_of_cc && "Degrees of connected components computed incorrectly");
  assert(gens_of_cc == expected_gens_of_cc && "Genera of connected components computed incorrecty");
}


// ########################################
// (2) Tests of h0 computations
// ########################################

void test4(){
  std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
  std::vector<int> degrees = {3,-1,-1,1};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly");
  assert(bound == true && "The cohomology result should be a lower bound, but is marked as exact");
}

void test5(){
  std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
  std::vector<int> degrees = {6,-1,-1,-1};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 7 && "Cohomology determined incorrectly");
  assert(bound == true && "The cohomology result should be a lower bound, but is marked as exact");
}

void test6(){
  std::vector<std::vector<int>> edges = {{2,3},{3,0}};
  std::vector<int> degrees = {-1,1,-1,4};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 4 && "Cohomology determined incorrectly");
  assert(bound == false && "The cohomology result should be exact, but is marked merely as lower bound");
}

void test7(){
  std::vector<std::vector<int>> edges = {{2,3},{3,0}};
  std::vector<int> degrees = {-1,-1,5,-1};
  std::vector<int> genera = {0,1,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 5 && "Cohomology determined incorrectly");
  assert(bound == false && "The cohomology result should be exact, but is marked merely as lower bound");
}

void test8(){
  std::vector<std::vector<int>> edges = {};
  std::vector<int> degrees = {0,1,5,2};
  std::vector<int> genera = {0,0,0,0};
  bool bound;
  int h0 = h0_on_nodal_curve(degrees, edges, genera, bound);
  assert(h0 == 12 && "Cohomology determined incorrectly");
  assert(bound == false && "The cohomology result should be exact, but is marked merely as lower bound");
}


// ########################################
// (3) Tests of combinatoric computations
// ########################################

void test9(){
  std::vector<std::vector<int>> partitions;
  comp_partitions(3,2,{0,0},{3,3}, partitions);
  assert(partitions.size() == 4 && "Partitions computed incorrectly");
}

void test10(){
  std::vector<std::vector<int>> nodal_edges = {{0,1},{1,2}};
  std::vector<int> genera = {0,0,0};
  std::vector<std::vector<int>> partitions;
  comp_partitions_with_nodes(2,nodal_edges,genera,partitions);
  assert(partitions.size() == 15 && "Partitions computed incorrectly");
}

void test11(){
  assert(number_partitions(10,3,5) == 6 && "Wrong number of partitions computed");
}


// ########################################
// (4) Test for sums of vectors
// ########################################

void test12(){
  std::vector<boost::multiprecision::int128_t> v = {1,2,3};
  std::vector<std::vector<boost::multiprecision::int128_t>> v2 = {{1,2,3},{4,5,6}};
  assert(sum(v) == 6 && "Wrong sum of vector computed");
  assert(sum(v2) == 21 && "Wrong sum of vector of vector computed");
}


// ########################################
// (5) Test for printing of vectors
// ########################################

void test13(){
  std::vector<std::vector<int>> edges = {{1,2},{3,4},{2,5},{6,4},{7,8},{0,9}};
  std::vector<int> degrees = {-2,3,4,-1,0,5,7,8,-9,9};
  std::vector<int> genera = {0,1,0,1,0,1,0,1,0,1};
  std::vector<std::vector<std::vector<int>>> edges_of_cc;
  std::vector<std::vector<int>> degs_of_cc, gens_of_cc;
  find_connected_components(edges, degrees, genera, edges_of_cc, degs_of_cc, gens_of_cc);
  std::cout << "-------------------------------------------\n";
  std::cout << "Computed the connected components of a graph.\n";
  std::cout << "We use this to test the printing of vectors and of (vectors of vectors).\n";
  std::cout << "-------------------------------------------\n\n";
  for (int i = 0; i < edges_of_cc.size(); i++){
    std::cout << "Component " << std::to_string(i) << "\n";
    print_vector_of_vector("Edges:\n", edges_of_cc[i]);
    print_vector("Degrees: ", degs_of_cc[i]);
    print_vector("Genera: ", gens_of_cc[i]);
    std::cout << "\n";
  }
  std::vector<std::vector<std::vector<boost::multiprecision::int128_t>>> expected_edges_of_cc = {{{0,1},{2,1}},{{0,1},{1,2}},{{0,1}},{{0,1}}};
  std::vector<std::vector<boost::multiprecision::int128_t>> expected_degs_of_cc = {{-1,0,7},{3,4,5},{8,-9},{-2,9}};
  std::vector<std::vector<boost::multiprecision::int128_t>> expected_gens_of_cc = {{1,0,0},{1,0,1},{1,0},{0,1}};
  std::cout << "-------------------------------------------\n";
  std::cout << "For these connected components we expect the following results.\n";
  std::cout << "-------------------------------------------\n\n";
  for (int i = 0; i < edges_of_cc.size(); i++){
    std::cout << "Component " << std::to_string(i) << "\n";
    print_vector_of_vector("Edges:\n", expected_edges_of_cc[i]);
    print_vector("Degrees: ", expected_degs_of_cc[i]);
    print_vector("Genera: ", expected_gens_of_cc[i]);
    std::cout << "\n";
  }
  assert(1 == 1);
}
