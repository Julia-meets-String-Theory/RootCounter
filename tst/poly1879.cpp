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
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{28950852, 21078338, 7243403, 1560494, 218906, 19526, 1358, 104}, {2242073, 1819768, 636926, 119012, 10500, 330, 0, 0}, {48482, 33768, 7878, 754, 0, 0, 0, 0}, {370, 92, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 0, 3736, 2626, 496, 51, 4}, {0, 0, 0, 84, 63, 6, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(20, 6));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
