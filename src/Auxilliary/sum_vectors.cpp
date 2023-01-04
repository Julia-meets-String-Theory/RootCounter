boost::multiprecision::int128_t sum(const std::vector<std::vector<boost::multiprecision::int128_t>> &values)
{
    boost::multiprecision::int128_t sum = 0;
    for (int i = 0; i < values.size(); i++){
        for (int j = 0; j < values[i].size(); j++){
            sum += values[i][j];
        }
    }
    return sum;
}

int sum(const std::vector<std::vector<int>> &values)
{
    int sum = 0;
    for (int i = 0; i < values.size(); i++){
        sum += std::accumulate(values[i].begin(), values[i].end(), 0);
    }
    return sum;
}
