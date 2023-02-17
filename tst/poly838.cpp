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
  count_roots("7 16 48 32 16 16 16 16 0 0 0 0 0 0 0 12 2 1 2 1 5 0 4 0 5 6 3 4 3 6 0 2 2 4 1 5 1 6 1 3 6 20 8 3 5 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32845047, 20641615, 6048558, 1075389, 122219, 8559, 477, 30}, {1739918, 1137880, 295128, 38834, 2010, 27, 0, 0}, {20615, 9155, 717, 13, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 5817, 6791, 1071, 84, 23, 0}, {0, 0, 0, 23, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
