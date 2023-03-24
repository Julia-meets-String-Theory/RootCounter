#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 32 32 32 32 16 0 0 0 0 0 0 11 3 1 3 2 4 3 4 3 5 0 4 0 4 5 0 2 1 5 1 2 1 2 6 20 8 3 5 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{35004914, 20350604, 5385038, 859253, 86464, 5738, 272, 10}, {1396842, 706580, 134879, 13420, 636, 12, 0, 0}, {9258, 1822, 98, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 29926, 12397, 1510, 116, 2, 0}, {0, 0, 209, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
