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
  count_roots("9 16 32 16 16 16 16 16 16 16 0 0 0 0 0 0 0 0 0 14 2 1 3 1 3 2 5 1 6 0 6 3 8 5 8 7 4 0 8 0 7 4 2 4 5 6 1 7 6 20 8 3 6 0 7", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{28954543, 21074384, 7243577, 1557543, 219947, 19856, 1307, 114}, {2237908, 1820659, 642014, 121406, 10647, 327, 0, 0}, {49877, 33865, 6961, 625, 0, 0, 0, 0}, {216, 46, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 0, 1886, 1779, 423, 29, 4}, {0, 0, 0, 30, 27, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  boost::multiprecision::int128_t total = (boost::multiprecision::int128_t) (pow(20, 6));
  if ((sum(n_exact) + sum(n_lower_bound) != total) || (n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
    return -1;
  }
}
