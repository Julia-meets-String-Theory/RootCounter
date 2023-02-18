#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 12 12 12 12 12 12 0 0 0 0 0 0 9 3 0 5 0 5 3 0 4 2 3 1 5 2 4 1 4 1 2 4 12 8 3 3 0 9";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{8910, 9240, 1650, 814, 66, 33, 22, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(12, 4)));
}
