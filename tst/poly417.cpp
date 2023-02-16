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
  count_roots("7 16 32 32 16 16 16 32 0 0 0 0 0 0 0 12 2 1 2 1 3 2 5 0 5 2 6 3 4 0 6 0 6 4 1 4 3 5 1 6 6 20 8 3 6 0 12", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32857596, 20722495, 6057400, 1079383, 120451, 8313, 466, 14, 0, 0, 0, 0, 0}, {1723530, 1074066, 264536, 32833, 1860, 24, 0, 0, 0, 0, 0, 0, 0}, {18545, 7982, 895, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 14056, 11214, 3268, 640, 96, 17, 0, 0, 0, 0, 0}, {0, 0, 147, 56, 21, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}