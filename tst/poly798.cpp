// ####################
// 1. Include libraries
// ####################

#include "include.cpp"


// ####################
// 2. Execute tests
// ####################

int main(int argc, char* argv[]){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("7 16 16 64 16 16 16 16 0 0 1 0 0 0 0 11 1 0 3 2 4 0 4 2 6 3 6 0 5 1 5 6 1 2 3 4 2 5 6 20 8 3 5 0 11", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{641557600, 231118800, 37370000, 3417600, 157600, 2400, 0, 0, 0, 0, 0, 0}, {36184800, 16349600, 2840800, 147600, 0, 0, 0, 0, 0, 0, 0, 0}, {469600, 128800, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{49516800, 165517600, 68256000, 13745200, 1494400, 80800, 6400, 0, 0, 0, 0, 0}, {892000, 7016400, 3139200, 513600, 12000, 0, 0, 0, 0, 0, 0, 0}, {0, 54400, 9600, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 798 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 798 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 798 failed");
}
