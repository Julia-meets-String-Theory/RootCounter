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
  count_roots("6 12 12 12 12 12 12 0 0 0 0 0 0 9 3 0 5 0 5 3 0 4 2 3 1 5 2 4 1 4 1 2 4 12 8 3 3 0 9", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{8910, 9240, 1650, 814, 66, 33, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 22, 0, 0, 1}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 128 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 128 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 128 failed");
}
