#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 64 16 32 16 16 0 1 0 0 0 0 10 3 0 3 1 3 1 3 2 0 2 5 0 4 2 4 5 1 5 1 4 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{736011640, 381496374, 90909480, 12756465, 1006800, 36000, 1600}, {30428570, 16550671, 3376000, 238800, 3600, 0, 0}, {196800, 33200, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{131160, 4319626, 1765720, 576735, 97600, 13600, 800}, {2230, 17729, 16800, 12000, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
