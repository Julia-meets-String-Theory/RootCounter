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
  count_roots("7 16 48 16 16 32 16 16 0 0 0 0 0 0 0 12 2 1 3 1 3 2 6 0 5 0 4 6 4 5 0 3 2 5 1 6 1 4 1 4 6 20 8 3 5 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32844379, 20644971, 6038994, 1076984, 122787, 8658, 406, 24}, {1740840, 1134088, 306918, 39182, 1920, 30, 0, 0}, {20654, 8228, 579, 22, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 6132, 2927, 1088, 149, 17, 1}, {0, 0, 22, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
