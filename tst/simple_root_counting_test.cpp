// ####################
// (0) Include libraries
// ####################

#include "include.cpp"


// ########################################
// (1) Make simple root counting
// ########################################

void test0(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("2 -1 -1 0 0 1 0 1 0 2 8 0 1 0 1", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{1, 0}, {0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0}, {0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 0 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 0 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 0 failed");
}

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

void test4(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("4 2 6 2 2 0 0 0 0 7 0 1 0 1 1 2 1 2 0 3 1 3 2 3 4 3 8 1 1 0 7", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{5, 20, 17, 20, 16, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 2, 0, 1, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 4 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 4 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 4 failed");
}

void test5(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("1 0 1 0 1 2 1 0 0 0 0", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{3}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{1}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 5 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 5 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 5 failed");
}

void test6(const std::string & full_path){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  std::vector<std::vector<std::vector<int>>> unsorted_setups;
  count_roots("5 6 0 4 6 0 0 0 0 0 0 9 0 1 0 1 0 2 0 2 0 3 2 3 2 3 3 4 3 4 5 2 8 4 4 0 9", full_path, true, n_exact, n_lower_bound, unsorted_setups);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected = {{0, 1, 4, 4, 8, 5, 4, 2, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected = {{0, 0, 0, 0, 0, 1, 0, 2, 0, 1}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for simple root counting 6 failed");
  assert(n_exact == n_exact_expected && "Test for simple root counting 6 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for simple root counting 6 failed");
}


// ########################################
// (2) Execute the tests
// ########################################

int main(int argc, char* argv[]){
	test0(argv[0]);
  test1(argv[0]);
	test2(argv[0]);
	test3(argv[0]);
	test4(argv[0]);
	test5(argv[0]);
  test6(argv[0]);
}
