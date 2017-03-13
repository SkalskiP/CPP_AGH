#include "Palindrome.h"
using namespace std;

bool is_palindrome(std::string str) {
    int len = str.length();
    for(int index = 0; index < len/2; index ++) {
        if (str[index] != str[len-1-index]) {
            return false;
        }
    }
    return true;
}
