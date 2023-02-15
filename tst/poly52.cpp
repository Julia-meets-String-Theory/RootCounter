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
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{34980351, 20149232, 5402789, 856967, 81012, 4287, 74, 4, 0, 0, 0, 0}, {1438026, 862358, 183547, 15688, 579, 9, 0, 0, 0, 0, 0, 0}, {9794, 1408, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 51, 8160, 4676, 838, 53, 0, 0, 0, 0, 0}, {0, 0, 0, 25, 18, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
