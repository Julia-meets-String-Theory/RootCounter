void test_polytope_88(){
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact, n_lower_bound;
  count_roots("5 16 80 32 16 16 0 1 0 0 0 9 4 0 0 3 2 3 2 4 0 1 1 4 1 3 1 2 1 2 6 20 8 3 5 0 9", n_exact, n_lower_bound);
  std::vector<std::vector<boost::multiprecision::int128_t>> n_exact_expected =
      {{781743600, 163235200, 13271200, 504800, 0, 0, 0, 0, 0, 0}, {25196800, 5967200, 399200, 0, 0, 0, 0, 0, 0, 0}, {106800, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  std::vector<std::vector<boost::multiprecision::int128_t>> n_lower_bound_expected =
      {{0, 206872800, 66014000, 9318400, 692000, 24800, 1600, 0, 0, 0}, {0, 5200000, 1355600, 88800, 0, 0, 0, 0, 0, 0}, {0, 7200, 0, 0, 0, 0, 0, 0, 0, 0}};
  assert(sum(n_exact) + sum(n_lower_bound) == sum(n_exact_expected) + sum(n_lower_bound_expected) && "Test for polytope 88 failed");
  assert(n_exact == n_exact_expected && "Test for polytope 88 failed");
  assert(n_lower_bound == n_lower_bound_expected && "Test for polytope 88 failed");
}
