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
  count_roots("6 16 32 32 32 32 16 0 0 0 0 0 0 11 1 0 2 0 2 1 2 1 3 2 4 1 0 5 4 5 3 5 3 4 3 4 6 20 8 3 5 0 11", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{34908682, 20592434, 5217628, 852537, 109894, 11414, 768, 24, 0, 0, 0, 0}, {1396458, 715731, 127552, 13524, 918, 39, 0, 0, 0, 0, 0, 0}, {6388, 4874, 320, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 31922, 7180, 1368, 284, 18, 3, 0, 0, 0, 0}, {0, 0, 36, 4, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
