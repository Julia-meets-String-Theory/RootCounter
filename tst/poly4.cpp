#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "4 12 24 24 12 0 0 0 0 7 3 0 2 0 2 3 1 0 1 3 1 2 1 2 4 12 8 3 3 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{11110, 7601, 1672, 275, 66, 11, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 0, 1}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(12, 4)));
}
