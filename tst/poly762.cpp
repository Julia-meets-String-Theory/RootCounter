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
  count_roots("7 16 16 32 32 32 16 16 0 0 0 0 0 0 0 12 1 0 3 2 3 2 4 0 4 1 4 2 4 3 6 0 5 1 5 6 3 6 2 5 6 20 8 3 5 0 12", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
  {{32858151, 20703000, 6040190, 1077204, 121534, 8446, 314, 12, 0, 0, 0, 0, 0}, {1722871, 1093360, 285368, 35811, 1881, 30, 0, 0, 0, 0, 0, 0, 0}, {18984, 6702, 280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
   {{0, 0, 14102, 7428, 3091, 758, 104, 6, 0, 0, 0, 0, 0}, {0, 0, 242, 107, 24, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
   if ((sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
