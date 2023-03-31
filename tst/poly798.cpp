#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "7 16 16 64 16 16 16 16 0 0 1 0 0 0 0 11 1 0 3 2 4 0 4 2 6 3 6 0 5 1 5 6 1 2 3 4 2 5 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{690950608, 396588650, 105619124, 16935977, 1544800, 72800, 3200}, {37074570, 23365071, 5980000, 656400, 9600, 0, 0}, {469600, 183200, 10000, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{123792, 47750, 6876, 226823, 107200, 10400, 3200},{2230, 929, 0, 4800, 2400, 0, 0},{0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
