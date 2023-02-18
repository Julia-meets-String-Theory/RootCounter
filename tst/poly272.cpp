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
  count_roots("6 16 64 16 32 16 16 0 1 0 0 0 0 10 3 0 3 1 3 1 3 2 0 2 5 0 4 2 4 5 1 5 1 4 6 20 8 3 5 0 6", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{736011640, 229717974, 31225880, 2127265, 47600, 0, 0}, {30428570, 11338671, 1224000, 0, 0, 0, 0}, {196800, 2000, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{131160, 156098026, 61449320, 11205935, 1056800, 49600, 2400}, {2230, 5229729, 2168800, 250800, 3600, 0, 0}, {0, 31200, 0, 0, 0, 0, 0}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(20, 7));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
