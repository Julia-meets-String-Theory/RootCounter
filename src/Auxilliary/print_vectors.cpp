// (1) Print vectors to the console
void print_vector(const std::string &message, const std::vector<int> &values)
{
    std::cout << message;
    for (auto i: values)
        std::cout << i << ", ";
    std::cout << "\n";
}
void print_vector(const std::string &message, const std::vector<boost::multiprecision::int128_t> &values)
{
    std::cout << message;
    for (auto i: values)
        std::cout << i << ", ";
    std::cout << "\n";
}


// (2) Print vectors of vectors to the console
void print_vector_of_vector(const std::string &message, const std::vector<std::vector<int>> &values)
{
    std::cout << message;
    for (int i = 0; i < values.size(); i++){
        print_vector("", values[i]);
    }
    std::cout << "\n";
}
void print_vector_of_vector(const std::string &message, const std::vector<std::vector<boost::multiprecision::int128_t>> &values)
{
    std::cout << message;
    for (int i = 0; i < values.size(); i++){
        print_vector("", values[i]);
    }
    std::cout << "\n";
}

// (3) Print vectors to a file
void print_vector_to_file(std::ofstream &file, const std::string &message, const std::vector<int> &values)
{
    file << message << "[";
    for (int i = 0; i < values.size() - 1; i++){
        file << std::to_string(values[i]) << ", ";
    }
    file << std::to_string(values.back()) << "]\n";
}

void print_vector_to_file(std::ofstream &file, const std::string &message, const std::vector<boost::multiprecision::int128_t> &values)
{
    file << message << "[";
    for (int i = 0; i < values.size() - 1; i++){
        file << values[i] << ", ";
    }
    file << values.back() << "]\n";
}

void print_vector_of_vector_to_file(std::ofstream &file, const std::string &message, const std::vector<std::vector<int>> &values)
{
    file << message << "\n";
    for (int i = 0; i < values.size(); i++){
        print_vector_to_file(file, "", values[i]);
    }
}

void print_vector_of_vector_to_file(std::ofstream &file, const std::string &message, const std::vector<std::vector<boost::multiprecision::int128_t>> &values)
{
    file << message << "\n";
    for (int i = 0; i < values.size(); i++){
        print_vector_to_file(file, "", values[i]);
    }
}
