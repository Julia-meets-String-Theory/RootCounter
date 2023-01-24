// ####################
// (0) Include libraries
// ####################

#include "include.cpp"


// ########################################
// (1) Make simple root counting
// ########################################

void test1(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("2 0 0 0 0 2 0 1 0 1 1 2 8 0 1 0 2", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{1, 0, 0}, {0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 1}, {0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 1 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 1 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 1 failed");
}

void test2(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("2 0 0 0 0 2 0 1 0 1 1 4 8 0 1 0 2", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{3, 0, 0}, {0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 1}, {0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 2 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 2 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 2 failed");
}

void test3(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("3 1 2 1 0 0 0 5 0 1 0 1 1 2 1 2 0 2 3 2 8 0 1 0 5", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 2, 4, 1, 0}, {0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 3 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 3 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 3 failed");
}


// ########################################
// (2) Execute the tests
// ########################################

int main(int argc, char* argv[]){
  test1(argv[0]);
	test2(argv[0]);
	test3(argv[0]);
}
