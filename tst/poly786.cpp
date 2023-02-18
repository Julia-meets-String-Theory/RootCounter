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
  count_roots("7 16 32 32 16 16 32 16 0 0 0 0 0 0 0 12 2 1 3 1 6 5 4 0 4 6 5 0 0 3 2 4 2 6 1 5 1 5 2 3 6 20 8 3 5 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32860461, 20719735, 6053632, 1080597, 121891, 8807, 560, 33}, {1719897, 1076991, 269709, 33335, 1839, 36, 0, 0}, {19661, 6835, 680, 25, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 14120, 8975, 1855, 168, 9, 2}, {0, 0, 134, 13, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(20, 6));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
