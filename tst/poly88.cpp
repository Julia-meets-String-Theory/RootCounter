#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "5 16 80 32 16 16 0 1 0 0 0 9 4 0 0 3 2 3 2 4 0 1 1 4 1 3 1 2 1 2 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{781680888, 366819888, 76851304, 8250400, 362000, 0, 0},{25196800, 11167200, 1694800, 64800, 0, 0, 0},{106800, 7200, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{62712, 3288112, 2433896, 1572800, 330000, 24800, 1600},{0, 0, 60000, 24000, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
