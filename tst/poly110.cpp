#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 48 32 32 16 16 0 1 0 0 0 0 10 2 1 3 0 3 1 4 2 4 0 5 0 5 4 2 3 2 3 1 5 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{738662983, 380375495, 90881815, 12997951, 942776, 47200, 3200}, {27732238, 14776766, 2366376, 148800, 2400, 0, 0}, {168000, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{301017, 6986505, 2888985, 574849, 68824, 6800, 800}, {5762, 51234, 6824, 2400, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
