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
  count_roots(
    "9 16 16 16 16 32 16 16 16 16 0 0 0 0 0 0 0 0 0 14 2 1 4 1 4 2 5 3 5 4 6 0 6 4 6 5 3 0 0 8 3 7 7 8 2 8 1 7 6 20 8 3 6 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{}};
  if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
