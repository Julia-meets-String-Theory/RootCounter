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
  count_roots("5 12 24 12 12 12 0 0 0 0 0 8 3 0 4 0 2 3 2 4 1 0 1 3 1 4 1 2 4 12 8 3 3 0 8", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{10010, 8360, 1782, 484, 55, 44, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 0, 0, 1}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(12, 4));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
