// Write a function in a language of your choice which, when passed two sorted arrays of integers
// returns an array of any numbers which appear in both. No value should appear in the returned
// array more than once.
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// find common values in 2 sorted arrays - a1 and a2 needs to be sorted
vector<int> common_values(const vector<int>& a1, const vector<int>& a2) {
    vector<int> result;
    int i = 0, j = 0;
    uint64_t a1_size = a1.size();
    uint64_t a2_size = a2.size();
    while(i < a1_size && j < a2_size) {
        if(a1[i] == a2[j]) {
            if(result.empty() || (result.back() != a1[i])) {
                result.push_back(a1[i]);
                i++; j++;
            }
        } else if(a1[i] < a2[j]){
            i++;
        } else {
            j++;
        }
    }
    return result;
}

int main() {
    vector<int> arr1 = {2, 3, 4, 5, 5, 7, 10, 120};
    vector<int> arr2 = {1, 2, 3, 6, 7, 8, 9, 12, 13, 120};
    vector<int> result = common_values(arr1, arr2);
    for(int num : result) {
        cout << num << endl;
    }
    return 0;
}