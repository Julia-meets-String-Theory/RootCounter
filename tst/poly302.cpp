#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 32 32 32 32 16 0 0 0 0 0 0 11 1 0 2 0 2 1 2 1 3 2 4 1 0 5 4 5 3 5 3 4 3 4 6 20 8 3 5 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{34908682, 20592434, 5217628, 852537, 109894, 11448, 776, 26}, {1396458, 715731, 127552, 13524, 918, 39, 0, 0}, {6388, 4874, 320, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 31922, 7180, 1368, 250, 10, 1}, {0, 0, 36, 4, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
