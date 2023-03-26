#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "4 12 36 12 12 0 1 0 0 6 3 0 2 0 2 3 0 1 1 3 1 2 4 12 8 2 3 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{0, 0, 0, 0, 0, 0, 0}, {142560, 95040, 4752, 6336, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 144}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(12, 5)));
}
