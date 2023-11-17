#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

bool find_sum_of_two(const std::vector<size_t>& vals, size_t target) {
    std::unordered_set<size_t> vals_found;
    // trying to find an element in vals_found unordered set,
    // which is equal to target minus that element
    for(size_t el : vals) {
        if(vals_found.find(target - el) != vals_found.end()) {
            return true;
        }
        vals_found.insert(el);
    }
    return false;
}

int main() {
    std::vector<size_t> vec1 = {5, 7, 1, 2, 8, 4, 3};
    assert(find_sum_of_two(vec1, 10));

    std::vector<size_t> vec2 = {1, 2, 3, 4, 5, 6, 7, 8};
    assert(find_sum_of_two(vec2, 14));

    std::vector<size_t> vec3 = {0};
    assert(!find_sum_of_two(vec3, 0));

    return 0;
}
