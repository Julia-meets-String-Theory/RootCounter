#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "8 16 32 32 16 16 16 16 16 0 0 0 0 0 0 0 0 13 2 1 2 1 4 1 4 3 5 0 5 2 3 0 7 0 6 3 6 7 4 5 2 7 1 6 6 20 8 3 5 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{30846440, 20949495, 6648992, 1310068, 166850, 13272, 844, 50}, {1997602, 1457977, 455326, 72081, 4884, 111, 0, 0}, {34270, 17032, 2118, 84, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 13266, 6660, 1826, 385, 12, 6}, {0, 0, 242, 107, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
