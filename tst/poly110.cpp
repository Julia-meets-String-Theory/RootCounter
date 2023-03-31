#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 48 32 32 16 16 0 1 0 0 0 0 10 2 1 3 0 3 1 4 2 4 0 5 0 5 4 2 3 2 3 1 5 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{738662983, 387249095, 93472615, 12861151, 845576, 30400, 0}, {27732238, 14827166, 2366376, 141600, 0, 0, 0}, {168000, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{301017, 112905, 298185, 711649, 166024, 23600, 4000}, {5762, 834, 6824, 9600, 2400, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
