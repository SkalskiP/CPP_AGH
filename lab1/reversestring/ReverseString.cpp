#include "ReverseString.h"

std::string reverse(std::string str) {
    int len = str.length();
    if (len == 1 or len == 0) {
        return str;
    }
    else {
        return (str[len-1] + reverse(str.substr(1,len-2)) + str[0]);
    }
}