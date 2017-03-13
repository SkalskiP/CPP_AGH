#include "DoubleBasePalindromes.h"
using namespace std;


uint64_t DoubleBasePalindromes(int max_vaule_exculsive) {
    int suma = 0;
    for(int number = 1; number <= max_vaule_exculsive; number++) {
        string s = std::to_string(number);
        if (is_palindrome(s)) {
            string binary_number = to_binary(number);
            if (is_palindrome(binary_number)) {
                //cout << number << ", " << binary_number << endl;
                suma = suma + number;
            }
        }
    }
    return suma;
}

bool is_palindrome(std::string str) {
    int len = str.length();
    for(int index = 0; index < len/2; index ++) {
        if (str[index] != str[len-1-index]) {
            return false;
        }
    }
    return true;
}

std::string to_binary(int number) {
    string binary_number = "";
    while (number > 0) {
        int next_dig = number%2;
        number = number/2;
        string next_char = std::to_string(next_dig);
        binary_number = next_char + binary_number;
    }
    return binary_number;
}



