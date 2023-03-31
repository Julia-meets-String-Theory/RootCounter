#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 80 16 16 16 16 0 1 0 0 0 0 10 2 3 0 2 4 3 0 5 4 5 1 3 1 2 0 1 1 4 1 5 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{733798300, 383958940, 92704840, 12534000, 900000, 26000, 0},{32742000, 17946000, 3720000, 336000, 0, 0, 0},{306000, 108000, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{59300, 17060, 1160, 608000, 208000, 18400, 2000},{0, 0, 0, 6000, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
