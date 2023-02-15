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
  count_roots("10 16 16 16 16 16 16 16 16 16 16 0 0 0 0 0 0 0 0 0 0 15 1 0 2 0 4 1 5 0 6 1 6 5 8 6 9 5 8 9 7 9 3 8 3 7 2 7 3 4 2 4 6 20 8 3 6 0 15", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected 
      {{690950608, 250171050, 40113524, 3586377, 157600, 2400, 0, 0, 0, 0, 0, 0}, {37074570, 16720271, 2840800, 147600, 0, 0, 0, 0, 0, 0, 0, 0}, {469600, 128800, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{123792, 146465350, 65512476, 13576423, 1494400, 80800, 6400, 0, 0, 0, 0, 0},{2230, 6645729, 3139200, 513600, 12000, 0, 0, 0, 0, 0, 0, 0},{0, 54400, 9600, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 798 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 798 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 798 failed");
}
