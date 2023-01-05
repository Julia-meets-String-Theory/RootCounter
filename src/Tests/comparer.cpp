bool comparer(const std::vector<std::vector<boost::multiprecision::int128_t>> &n_exact,
              const std::vector<std::vector<boost::multiprecision::int128_t>> &n_lower_bound,
              const std::vector<std::vector<boost::multiprecision::int128_t>> &n_exact_expected,
              const std::vector<std::vector<boost::multiprecision::int128_t>> &n_lower_bound_expected)
{
    if (sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)){
      return false;
    }
    if ((n_exact != n_exact_expected) || (n_lower_bound != n_lower_bound_expected)){
      return false;
    }
    return true;
}
