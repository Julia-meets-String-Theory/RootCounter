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
  count_roots("8 16 16 16 16 32 32 16 16 0 0 0 0 0 0 0 0 13 3 0 4 1 5 1 5 4 3 7 6 7 0 2 2 6 4 7 3 4 0 5 1 6 2 5 6 20 8 3 6 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{30845702, 20949103, 6682151, 1314966, 166442, 13547, 849, 65}, {2000040, 1455999, 437511, 68093, 4875, 99, 0, 0}, {33043, 17509, 2633, 140, 0, 0, 0, 0}, {54, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 0, 4760, 2162, 195, 20, 0}, {0, 0, 0, 36, 6, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(20, 6));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
