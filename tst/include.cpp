#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <fstream>
#include <iostream>
#include <mutex>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <vector>

// Include functionality of boost
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

// Include my specialized files
#include "../src/ThreadSafe/guards.cpp"
#include "../src/Auxilliary/print_vectors.cpp"
#include "../src/Auxilliary/sum_vectors.cpp"
#include "../src/Auxilliary/handle_input.cpp"
#include "../src/Auxilliary/return_result.cpp"
#include "../src/Graphs/graphs.cpp"
#include "../src/H0/compute_h0_on_circuit.cpp"
#include "../src/H0/compute_h0.cpp"
#include "../src/Combinatorics/combinatorics.cpp"
#include "../src/Counter/distributeGlobalSections.cpp"
#include "../src/Counter/rootCounter-v3.cpp"
#include "../src/Counter/iterator.cpp"

// Optimizations for speedup
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
