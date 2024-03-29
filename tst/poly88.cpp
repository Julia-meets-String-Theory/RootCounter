#include "include.cpp"

int main(int argc, char* argv[]){
  std::string input = "5 16 80 32 16 16 0 1 0 0 0 9 4 0 0 3 2 3 2 4 0 1 1 4 1 3 1 2 1 2 6 20 8 3 5 0 6";
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{781680888, 366819888, 78164104, 9089200, 533200, 16400, 0},{25196800, 11167200, 1746400, 88800, 0, 0, 0},{106800, 7200, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{62712, 3288112, 1121096, 734000, 158800, 8400, 1600},{0, 0, 8400, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}};
  return conduct_test(input, argv[0], n_exact_expected, n_lower_bound_expected, (boost::multiprecision::int128_t) (pow(20, 7)));
}
