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
  count_roots("6 16 64 16 32 16 16 0 1 0 0 0 0 10 3 0 3 1 3 1 3 2 0 2 5 0 4 2 4 5 1 5 1 4 6 20 8 3 5 0 10", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{683678800, 212949600, 29103200, 1932000, 43200, 0, 0, 0, 0, 0, 0}, {29538800, 10968000, 1224000, 0, 0, 0, 0, 0, 0, 0, 0}, {196800, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{52464000, 172866400, 63572000, 11401200, 1061200, 49600, 2400, 0, 0, 0, 0}, {892000, 5600400, 2168800, 250800, 3600, 0, 0, 0, 0, 0, 0}, {0, 31200, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 110 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 110 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 110 failed");
}
