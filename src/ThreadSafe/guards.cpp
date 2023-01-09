boost::mutex myGuard, myGuard2;

void UpdateCountThreadSafe(std::vector<boost::multiprecision::int128_t> & central,
                           const boost::multiprecision::int128_t & change_clear,
                           const boost::multiprecision::int128_t & change_unclear)
{
    boost::mutex::scoped_lock lock(myGuard);
    central[0] += change_clear;
    central[1] += change_unclear;
}

void UpdateUnsortedThreadSafe(std::vector<std::vector<std::vector<int>>> & list_unsorted,
                              const std::vector<std::vector<int>> & new_unsorted)
{
    boost::mutex::scoped_lock lock(myGuard2);
    if (std::find(std::begin(list_unsorted), std::end(list_unsorted), new_unsorted) == std::end(list_unsorted)){
        list_unsorted.push_back(new_unsorted);
    }
}
