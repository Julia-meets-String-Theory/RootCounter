#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "7 16 48 16 16 32 16 16 0 0 0 0 0 0 0 12 2 1 3 1 3 2 6 0 5 0 4 6 4 5 0 3 2 5 1 6 1 4 1 4 6 20 8 3 5 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32844379, 20644971, 6038994, 1076984, 122787, 8658, 406, 24}, {1740840, 1134088, 306918, 39182, 1920, 30, 0, 0}, {20654, 8228, 579, 22, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 6132, 2927, 1088, 149, 17, 1}, {0, 0, 22, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
