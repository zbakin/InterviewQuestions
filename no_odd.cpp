// Write a function in a language of your choice which, when passed a positive integer returns
// true if the decimal representation of that integer contains no odd digits and otherwise returns
// false.
#include <iostream>

using std::cout;
using std::endl;

// find out if number has only even digits
bool is_no_odd_digits(uint64_t num) {
    if(num == 0) return false;
    while(num != 0) {
        // find reminder, i.e. least significant digit
        uint64_t digit = num % 10;
        // check if digit is odd and fail if so
        if(digit % 2 == 1) return false;
        // shift by 1 digit, to check other digits
        num = num / 10;
    }
    return true;
}

int main() {
    uint16_t even_digit_num = 424;
    uint16_t odd_digit_num = 99;
    
    if(is_no_odd_digits(even_digit_num)) {
        cout << "Correct, no odd digit is found" << endl;
    } else {
        cout << "Wrong, odd digit is found" << endl;
    }

    if(is_no_odd_digits(odd_digit_num)) {
        cout << "Wrong, odd digit is found" << endl;
    } else {
        cout << "Correct, no odd digit is found" << endl;
    }
    
    return 0;
}