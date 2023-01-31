// ####################
// 1. Include libraries
// ####################

#include "include.cpp"


// ####################
// 2. Execute tests
// ####################

int main(int argc, char* argv[]){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("6 16 48 16 48 16 16 0 0 0 0 0 0 11 2 0 2 1 5 0 5 2 5 3 4 0 3 4 1 4 1 3 1 3 1 3 6 20 8 3 5 0 11", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected 
      {{34980351, 20149232, 5110469, 715533, 52346, 1308, 0, 0, 0, 0, 0, 0},{1438026, 862358, 173179, 10409, 0, 0, 0, 0, 0, 0, 0, 0},{9794, 1408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 292371, 149594, 33342, 3817, 127, 4, 0, 0, 0, 0},{0, 0, 10368, 5304, 597, 9, 0, 0, 0, 0, 0, 0},{0, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 52 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 52 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 52 failed");
}
