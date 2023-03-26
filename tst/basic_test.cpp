// ####################
// 0. Include libraries
// ####################

#include "include.cpp"


// ########################################
// (1) Tests of graph functionality
// ########################################

void test1(){
  std::vector<std::vector<int>> edges = {{0,1},{0,2},{3,4},{3,4},{5,6},{6,7}};
  assert(number_connected_components(edges) == 3 && "Connected components computed incorrectly");
}

void test2(){
  std::vector<std::vector<int>> edges = {{0,1},{0,2},{3,4},{3,4},{5,6},{6,7}};
  std::vector<int> vertices;
  std::vector<int> expected_vertices = {0,1,2,3,4,5,6,7};
  find_vertices(vertices, edges);
  assert(vertices == expected_vertices && "Vertices computed incorrectly");
}

void test3(){
  std::vector<std::vector<int>> edges = {{3,4},{3,4}};
  std::vector<std::vector<int>> edges2 = {};
  assert(betti_number(edges) == 1 && "Betti number computed incorrectly");
  assert(betti_number(edges2) == 0 && "Betti number computed incorrectly");
}

void test4(){
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

void test5(){
  std::vector<int> degrees = {0,1,2};
  std::vector<int> genera = {0,0,0};
  std::vector<std::vector<int>> edges = {{0,1},{0,1},{1,2}};
  std::vector<int> new_degrees, new_genera;
  std::vector<std::vector<int>> new_edges;
  int offset = simplify_by_removing_rational_leafs(degrees, edges, genera, new_degrees, new_edges, new_genera);
  std::vector<int> new_expected_degrees = {0,1};
  std::vector<int> new_expected_genera = {0,0};
  std::vector<std::vector<int>> new_expected_edges = {{0,1},{0,1}};
  int expected_offset = 2;
  assert(new_degrees == new_expected_degrees && "Removal of leafs (part 1) led to unexpected degrees");
  assert(new_genera == new_expected_genera && "Removal of leafs (part 1) led to unexpected genera");
  assert(new_edges == new_expected_edges && "Removal of leafs (part 1) led to unexpected edges");
  assert(offset == expected_offset && "Removal of leafs (part 1) led to unexpected offset");
}

void test6(){
  std::vector<int> degrees = {0,-1};
  std::vector<int> genera = {0,0};
  std::vector<std::vector<int>> edges = {{0,1}};
  std::vector<int> new_degrees, new_genera;
  std::vector<std::vector<int>> new_edges;
  int offset = simplify_by_removing_rational_leafs(degrees, edges, genera, new_degrees, new_edges, new_genera);
  std::vector<int> new_expected_degrees = {-1};
  std::vector<int> new_expected_genera = {0};
  std::vector<std::vector<int>> new_expected_edges = {};
  int expected_offset = 0;
  assert(new_degrees == new_expected_degrees && "Removal of leafs (part 2) led to unexpected degrees");
  assert(new_genera == new_expected_genera && "Removal of leafs (part 2) led to unexpected genera");
  assert(new_edges == new_expected_edges && "Removal of leafs (part 2) led to unexpected edges");
  assert(offset == expected_offset && "Removal of leafs (part 2) led to unexpected offset");
}

void test7(){
  std::vector<int> degrees = {0,1,2,3};
  std::vector<int> genera = {0,0,0,0};
  std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,3}};
  std::vector<int> new_degrees, new_genera;
  std::vector<std::vector<int>> new_edges;
  int offset = simplify_by_removing_rational_leafs(degrees, edges, genera, new_degrees, new_edges, new_genera);
  std::vector<int> new_expected_degrees = {1};
  std::vector<int> new_expected_genera = {0};
  std::vector<std::vector<int>> new_expected_edges = {};
  int expected_offset = 5;
  assert(new_degrees == new_expected_degrees && "Removal of leafs (part 3) led to unexpected degrees 3");
  assert(new_genera == new_expected_genera && "Removal of leafs (part 3) led to unexpected genera");
  assert(new_edges == new_expected_edges && "Removal of leafs (part 3) led to unexpected edges");
  assert(offset == expected_offset && "Removal of leafs (part 3) led to unexpected offset");
}


// ########################################
// (2) Tests of combinatoric computations
// ########################################

void test8(){
  std::vector<std::vector<int>> partitions;
  comp_partitions(3,2,{0,0},{3,3}, partitions);
  assert(partitions.size() == 4 && "Partitions computed incorrectly (test26)");
}

void test9(){
  std::vector<std::vector<int>> nodal_edges = {{0,1},{1,2}};
  std::vector<int> genera = {0,0,0};
	std::vector<int> minimal_local_sections = {0,0,0};
	std::vector<int> maximal_local_sections = {4,4,4};
  std::vector<std::vector<int>> local_degree_partitions;
  std::vector<bool> lower_bounds;
  distribute_global_sections(2, nodal_edges, genera, minimal_local_sections, maximal_local_sections, local_degree_partitions, lower_bounds);
  assert(local_degree_partitions.size() == 15 && "Partition of local degrees computed incorrectly (test27)");
  assert(lower_bounds.size() == 15 && "Lower bounds computed incorrectly (test27)");
}

void test10(){
  assert(number_partitions(10,3,5) == 6 && "Wrong number of partitions computed (test28)");
}


// ########################################
// (3) Test for sums of vectors
// ########################################

void test11(){
  std::vector<boost::multiprecision::int128_t> v = {1,2,3};
  std::vector<std::vector<boost::multiprecision::int128_t>> v2 = {{1,2,3},{4,5,6}};
  assert(sum(v) == 6 && "Wrong sum of vector computed (test29)");
  assert(sum(v2) == 21 && "Wrong sum of vector of vector computed (test29)");
}


// ########################################
// (4) Test for printing of vectors
// ########################################

void test_printing(){
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
  test_printing();
}
