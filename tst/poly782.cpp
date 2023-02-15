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
  count_roots("7 16 48 16 16 32 16 16 0 0 0 0 0 0 0 12 2 1 3 1 3 2 6 0 5 0 4 6 4 5 0 3 2 5 1 6 1 4 1 4 6 20 8 3 5 0 12", argv[0], true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected 
      {{690950608, 250171050, 40113524, 3586377, 157600, 2400, 0, 0, 0, 0, 0, 0}, {37074570, 16720271, 2840800, 147600, 0, 0, 0, 0, 0, 0, 0, 0}, {469600, 128800, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{123792, 146465350, 65512476, 13576423, 1494400, 80800, 6400, 0, 0, 0, 0, 0},{2230, 6645729, 3139200, 513600, 12000, 0, 0, 0, 0, 0, 0, 0},{0, 54400, 9600, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 798 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 798 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 798 failed");
}
