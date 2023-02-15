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
  count_roots("7 16 32 32 16 16 32 16 0 0 0 0 0 0 0 12 2 1 3 1 6 5 4 0 4 6 5 0 0 3 2 4 2 6 1 5 1 5 2 3 6 20 8 3 5 0 12", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected 
  {{32860461, 20719735, 6053632, 1080597, 120420, 8175, 438, 14, 0, 0, 0, 0, 0}, {1719897, 1076991, 269709, 33335, 1821, 30, 0, 0, 0, 0, 0, 0, 0}, {19661, 6835, 680, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
    {{0, 0, 14120, 8975, 3326, 800, 131, 21, 0, 0, 0, 0, 0}, {0, 0, 134, 13, 18, 6, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 798 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 798 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 798 failed");
}
