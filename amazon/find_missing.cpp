#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

size_t find_missing(const std::vector<size_t>& vals) {
    // calculate the sum of values of input vector vals
    size_t vals_sum = std::accumulate(vals.begin(), vals.end(), 0);
    size_t size_of_vals = vals.size();
    // calculate the sum of all values from 0 to size_of_vals
    size_t total_sum = size_of_vals * (size_of_vals + 1) / 2;

    return total_sum - vals_sum;
}

int main() {
    std::vector<size_t> vec1 = {5, 4, 6, 0, 2, 7, 3};
    assert(find_missing(vec1) == 1);

    std::vector<size_t> vec2 = {6, 0, 8, 5, 3, 1, 7, 9, 2};
    assert(find_missing(vec2) == 4);

    std::vector<size_t> vec3 = {0};
    assert(find_missing(vec3) == 1);
    return 0;
}
