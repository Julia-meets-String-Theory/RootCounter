#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "8 16 32 32 16 16 16 16 16 0 0 0 0 0 0 0 0 13 2 1 2 1 3 2 4 3 5 0 5 2 4 0 0 7 4 6 6 7 3 5 1 7 1 6 6 20 8 3 6 0 7";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{30840098, 20954897, 6654068, 1310452, 165464, 13050, 874, 50}, {2005760, 1454627, 444764, 70013, 4878, 105, 0, 0}, {31362, 18060, 3306, 60, 0, 0, 0, 0}, {308, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 0, 13076, 10864, 2878, 357, 42, 2},{0, 0, 294, 231, 60, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 6)));
}
