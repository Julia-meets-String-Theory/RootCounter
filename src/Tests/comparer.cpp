bool comparer(const std::vector<std::vector<boost::multiprecision::int128_t>> &n_exact,
              const std::vector<std::vector<boost::multiprecision::int128_t>> &n_lower_bound,
              const std::vector<std::vector<boost::multiprecision::int128_t>> &n_exact_expected,
              const std::vector<std::vector<boost::multiprecision::int128_t>> &n_lower_bound_expected)
{
        if (sum(n_exact) + sum(n_lower_bound) != sum(n_exact_expected) + sum(n_lower_bound_expected)){
        std::cout << "\n\nNot all roots have been found!\n";
        print_vector_of_vector("Found exact results:\n", n_exact);
        print_vector_of_vector("Expected exact results:\n", n_exact_expected);
        print_vector_of_vector("Found lower bounds:\n", n_lower_bound);
        print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
    }
    if (n_exact != n_exact_expected){
      print_vector_of_vector("\n\nFound exact results:\n", n_exact);
      print_vector_of_vector("Expected exact results:\n", n_exact_expected);
      return false;
    }
    if (n_lower_bound != n_lower_bound_expected){
      print_vector_of_vector("\n\nFound lower bounds:\n", n_lower_bound);
      print_vector_of_vector("Expected lower bounds:\n", n_lower_bound_expected);
      return false;
    }
    return true;
}
