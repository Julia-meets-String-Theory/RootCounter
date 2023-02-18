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
  count_roots("10 16 16 16 16 16 16 16 16 16 16 0 0 0 0 0 0 0 0 0 0 15 1 0 2 0 4 1 5 0 6 1 6 5 8 6 9 5 8 9 7 9 3 8 3 7 2 7 3 4 2 4 6 20 8 3 6 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(20, 6));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
