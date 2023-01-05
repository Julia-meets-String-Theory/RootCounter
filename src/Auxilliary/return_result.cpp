void return_result(const std::string & full_path,
                            const std::vector<std::vector<boost::multiprecision::int128_t>> & n_exact,
                            const std::vector<std::vector<boost::multiprecision::int128_t>> & n_lower_bound,
                            const int & numberBlowupsConsidered,
                            const int & numNodesMin,
                            const int & genus,
                            const int & root,
                            const int & h0Min,
                            const int & h0Max,
                            const int & b1,
                            const std::chrono::steady_clock::time_point & before,
                            const std::chrono::steady_clock::time_point & after,
                            const std::vector<std::vector<std::vector<int>>> & unsorted)
{

    // (1) Find absolute path
    std::string dir_path = full_path.substr(0, full_path.find_last_of("."));

    // (2) Save the computed numbers of to a result file.
    std::ofstream file1(dir_path + "/result.txt", std::ios::trunc);
    print_vector_of_vector_to_file(file1, "[[", n_exact);
    print_vector_of_vector_to_file(file1, "],\n[", n_lower_bound);
    file1 << "]];";
    file1.close();

    // (3) Save the unsorted setups to another file.
    std::ofstream file2(dir_path + "/unsorted_setups.txt", std::ios::trunc);
    for (int i = 0; i < unsorted.size(); i++){
        file2 << "##################\n";
        std::vector<std::vector<int>> nodal_edges_of_setup(unsorted[i].begin()+3, unsorted[i].end());
        print_vector_of_vector_to_file(file2, "Edges", nodal_edges_of_setup);
        print_vector_to_file(file2, "Genera ", unsorted[i][0]);
        print_vector_to_file(file2, "Degrees ", unsorted[i][1]);
        file2 << "Lower bound on h0: " << std::to_string(unsorted[i][2][0]) << "\n";
        file2 << "##################\n\n";
    }
    file2.close();

    // (4) By theory, we expect a certain number of root bundles. Compute that number and the number of root bundles we actually found.
    boost::multiprecision::int128_t geo_mult = (boost::multiprecision::int128_t) (pow(root, b1));
    boost::multiprecision::int128_t total_number_roots = ((boost::multiprecision::int128_t) (pow(root, 2 * genus))/geo_mult);
    boost::multiprecision::int128_t total_roots_found = sum(n_exact) + sum(n_lower_bound);

    // (5) Print the numbers we found.
    std::cout << "\n";
    for (int j = 0; j <= numberBlowupsConsidered; j++){
        std::cout << j + numNodesMin << ":\t";
        for (int i = 0; i <= h0Max - h0Min; i++){
            std::cout << n_exact[i][j] << "\t" << n_lower_bound[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "Total:\t";
    for (int i = 0; i <= h0Max - h0Min; i++){
        std::cout << sum(n_exact[i]) << "\t" << sum(n_lower_bound[i]) << "\t";
    }
    std::cout << "\n\n";

    // (6) Print the percentages we found.
    using LongFloat=boost::multiprecision::cpp_bin_float_quad;
    for (int j = 0; j <= numberBlowupsConsidered; j++){
        std::cout << j + numNodesMin << ":\t";
        for (int i = 0; i <= h0Max - h0Min; i++){
            LongFloat r1 = LongFloat(100) * LongFloat(n_exact[i][j]) / LongFloat(total_number_roots);
            LongFloat r2 = LongFloat(100) * LongFloat(n_lower_bound[i][j]) / LongFloat(total_number_roots);
            std::cout << std::setprecision(3) << r1 << "\t" << std::setprecision(3) << r2 << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "Total:\t";
    LongFloat percentage_counter;
    for (int i = 0; i <= h0Max - h0Min; i++){
        std::cout << std::setprecision(3) << LongFloat(100) * LongFloat(sum(n_exact[i])) / LongFloat(total_number_roots) << "\t";
        std::cout << std::setprecision(3) << LongFloat(100) * LongFloat(sum(n_lower_bound[i])) / LongFloat(total_number_roots) << "\t";
    }
    std::cout << "\n\n";
    
    // (7) Print summary
    std::cout << "\n##########################################\n";
    std::cout << "Results:\n";
    std::cout << "-----------------------\n";
    std::cout << "Number of roots found: " << (boost::multiprecision::int128_t) (geo_mult * total_roots_found) << "\n";
    std::cout << "Number of roots expected: " << (boost::multiprecision::int128_t) (pow(root, 2 * genus)) << "\n";
    std::cout << "Difference: " << (boost::multiprecision::int128_t) (pow(root, 2 * genus)) - (boost::multiprecision::int128_t) (geo_mult * total_roots_found) << "\n";
    std::cout << "Time for run: " << std::chrono::duration_cast<std::chrono::seconds>(after - before).count() << "[s]\n";
    std::cout << "##########################################\n\n";
    
}
