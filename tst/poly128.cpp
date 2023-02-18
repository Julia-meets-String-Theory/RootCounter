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
  count_roots("6 12 12 12 12 12 12 0 0 0 0 0 0 9 3 0 5 0 5 3 0 4 2 3 1 5 2 4 1 4 1 2 4 12 8 3 3 0 9", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{8910, 9240, 1650, 814, 66, 33, 22, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(12, 4));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
