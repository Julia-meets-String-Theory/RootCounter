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
      {{618557200, 225446400, 35072800, 2775600, 78400, 0, 0, 0, 0, 0, 0}, {25433200, 10638400, 971200, 0, 0, 0, 0, 0, 0, 0, 0}, {168000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{120406800, 161915600, 58698000, 10797200, 933200, 54000, 4000, 0, 0, 0, 0}, {2304800, 4189600, 1402000, 151200, 2400, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 110 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 110 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 110 failed");
}
