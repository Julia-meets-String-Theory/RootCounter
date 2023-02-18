#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "5 12 24 12 12 12 0 0 0 0 0 8 3 0 4 0 2 3 2 4 1 0 1 3 1 4 1 2 4 12 8 3 3 0 8";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{10010, 8360, 1782, 484, 55, 44, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 0, 0, 1}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(12, 4)));
}
