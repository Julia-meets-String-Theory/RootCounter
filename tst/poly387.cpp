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
  count_roots("6 16 80 16 16 16 16 0 1 0 0 0 0 10 2 3 0 2 4 3 0 5 4 5 1 3 1 2 0 1 1 4 1 5 6 20 8 3 5 0 10", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{710137600, 182982000, 19902000, 1134000, 34000, 0, 0, 0, 0, 0, 0}, {32742000, 10830000, 1224000, 60000, 0, 0, 0, 0, 0, 0, 0}, {306000, 72000, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{23720000, 200994000, 72804000, 12008000, 1074000, 44400, 2000, 0, 0, 0, 0}, {0, 7116000, 2496000, 282000, 0, 0, 0, 0, 0, 0, 0}, {0, 36000, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 387 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 387 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 387 failed");
}
