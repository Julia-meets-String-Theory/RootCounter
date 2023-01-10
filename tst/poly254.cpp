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
  count_roots("6 16 32 32 32 32 16 0 0 0 0 0 0 11 3 1 3 2 4 3 4 3 5 0 4 0 4 5 0 2 1 5 1 2 1 2 6 20 8 3 5 0 11 1", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{35004914, 20350604, 5220580, 759982, 60688, 2616, 0, 0, 0, 0, 0, 0}, {1396842, 706580, 129078, 11322, 360, 0, 0, 0, 0, 0, 0, 0}, {9258, 1822, 94, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 194384, 111668, 27286, 3238, 274, 10, 0, 0, 0, 0}, {0, 0, 6010, 2098, 276, 12, 0, 0, 0, 0, 0, 0}, {0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 254 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 254 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 254 failed");
}
