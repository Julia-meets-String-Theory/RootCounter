#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "7 16 32 32 16 16 16 32 0 0 0 0 0 0 0 12 2 1 2 1 3 2 5 0 5 2 6 3 4 0 6 0 6 4 1 4 3 5 1 6 6 20 8 3 6 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32857596, 20722495, 6057400, 1079383, 121460, 8793, 550, 31}, {1723530, 1074066, 264536, 32833, 1881, 24, 0, 0}, {18545, 7982, 895, 19, 0, 0, 0, 0}, {77, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 14056, 11214, 2259, 160, 12, 0}, {0, 0, 147, 56, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
