#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "5 16 80 32 16 16 0 1 0 0 0 9 4 0 0 3 2 3 2 4 0 1 1 4 1 3 1 2 1 2 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{781680888, 163221088, 13270504, 504800, 4400, 0, 0},{25196800, 5967200, 399200, 0, 0, 0, 0},{106800, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{62712, 206886912, 66014696, 9318400, 687600, 24800, 1600},{0, 5200000, 1355600, 88800, 0, 0, 0},{0, 7200, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
