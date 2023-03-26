#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 64 16 32 16 16 0 1 0 0 0 0 10 3 0 3 1 3 1 3 2 0 2 5 0 4 2 4 5 1 5 1 4 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{736011640, 381496374, 89689080, 12167665, 887600, 19200, 0}, {30428570, 16550671, 3311200, 205200, 0, 0, 0}, {196800, 33200, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{131160, 4319626, 2986120, 1165535, 216800, 30400, 2400}, {2230, 17729, 81600, 45600, 3600, 0, 0}, {0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
