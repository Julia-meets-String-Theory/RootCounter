#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "6 16 80 16 16 16 16 0 1 0 0 0 0 10 2 3 0 2 4 3 0 5 4 5 1 3 1 2 0 1 1 4 1 5 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{733798300, 189788940, 20364840, 1134000, 34000, 0, 0},{32742000, 10830000, 1224000, 60000, 0, 0, 0},{306000, 72000, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{59300, 194187060, 72341160, 12008000, 1074000, 44400, 2000},{0, 7116000, 2496000, 282000, 0, 0, 0},{0, 36000, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
