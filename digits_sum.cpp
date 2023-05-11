// Write a function in a language of your choice which, when passed a decimal digit X, returns the
// value of X+XX+XXX+XXXX. E.g. if the supplied digit is 3 it should return 3702
// (3+33+333+3333).
#include <iostream>

using std::cout;
using std::endl;

uint64_t sum_of_digits(int d) {
    // Explained:
    // XXXX + XXX + XX + X
    // 1111 * X + 111 * X + 11 * X + 1 * X
    // (1111 + 111 + 11 + 1) * X
    // 1234 * X
    uint64_t sum = 1234 * d;
    return sum;
}

int main() {
    cout << sum_of_digits(3) << endl;
    return 0;
}