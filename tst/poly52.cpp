#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 48 16 48 16 16 0 0 0 0 0 0 11 2 0 2 1 5 0 5 2 5 3 4 0 3 4 1 4 1 3 1 3 1 3 6 20 8 3 5 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{34980351, 20149232, 5402789, 856967, 83265, 4851, 116, 4}, {1438026, 862358, 183547, 15688, 597, 9, 0, 0}, {9794, 1408, 54, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 51, 8160, 2423, 274, 11, 0}, {0, 0, 0, 25, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
