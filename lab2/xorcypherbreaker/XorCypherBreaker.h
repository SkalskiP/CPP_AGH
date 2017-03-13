//
// Created by afghan on 08.03.17.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string to_binary(int number);
string add_bit_binary_numbers (string binary_num_1, string binary_num_2);
char binary_to_char(string binary_num);
vector <string> key_brut_force(void);

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);

#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
