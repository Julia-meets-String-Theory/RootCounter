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
  count_roots("6 16 48 32 32 16 16 0 1 0 0 0 0 10 2 1 3 0 3 1 4 2 4 0 5 0 5 4 2 3 2 3 1 5 6 20 8 3 5 0 10", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{738662983, 270495495, 41953954, 3212904, 83188, 0, 0, 0, 0, 0, 0},{27732238, 10971166, 979978, 0, 0, 0, 0, 0, 0, 0, 0},{168000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{301017, 116866505, 51816846, 10359896, 928412, 54000, 4000, 0, 0, 0, 0},{5762, 3856834, 1393222, 151200, 2400, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 110 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 110 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 110 failed");
}
