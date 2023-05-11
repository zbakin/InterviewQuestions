// The Fibonacci sequence is defined as a sequence of integers starting with 1 and 1, where each
// subsequent value is the sum of the preceding two. I.e.
// f(0) = 1
// f(1) = 1
// f(n) = f(n-1) + f(n-2) where n >= 2
// Write a program in a language of your choice to calculate the sum of the first 100 even-valued
// Fibonacci numbers
#include <iostream>

using std::cout;
using std::endl;

// as we are incrementing, use the maximum positive range for integers,
// hence unsigned long long aka uint64_t from stdint library
uint64_t fib_even_sum(int n) {
    uint64_t sum = 0;
    uint64_t prev = 1;
    uint64_t curr = 2; // first even valued fibonacci number, hence start from 2
    int count = 0;
    while(count < n) {
        if(curr % 2 == 0) { // check for even number
            sum += curr;
            ++count;
        }
        // find the next Fib number and set to curr
        uint64_t next = curr + prev;
        prev = curr;
        curr = next;
    }
    return sum;
}

int main() {
    uint64_t sum = 0;
    sum = fib_even_sum(100);
    cout << sum << endl;
    return 0;
}