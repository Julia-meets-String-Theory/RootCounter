#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "7 16 16 32 32 32 16 16 0 0 0 0 0 0 0 12 1 0 3 2 3 2 4 0 4 1 4 2 4 3 6 0 5 1 5 6 3 6 2 5 6 20 8 3 5 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{32858151, 20703000, 6040190, 1077204, 122758, 8972, 406, 18}, {1722871, 1093360, 285368, 35811, 1905, 30, 0, 0}, {18984, 6702, 280, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 14102, 7428, 1867, 232, 12, 0}, {0, 0, 242, 107, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
