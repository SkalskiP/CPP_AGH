#include "XorCypherBreaker.h"
using namespace std;
using std::find;
using std::vector;
using std::string;

string XorCypherBreaker(const std::vector<char> &cryptogram,
                        int key_length,
                        const std::vector<string> &dictionary) {

    int number_of_char = cryptogram.size();
    vector<string> all_keys = key_brut_force();

    string best_key = "";
    int best_key_matches = 0;
    for (int key_nr = 0; key_nr < all_keys.size(); key_nr++) {
        string key = all_keys[key_nr];
        cout << key_nr << " / " << all_keys.size() << " string: " << all_keys[key_nr] << " | best key: " << best_key << endl;
        int index;
        string decoded = "";
        for (index = 0; index < number_of_char; index ++) {
            int decoded_letter = binary_to_char(add_bit_binary_numbers(to_binary((int)cryptogram[index]), to_binary((int)key[index%3])));
            decoded += decoded_letter;
        }

        std::istringstream iss(decoded);

        int found_words = 0;
        do
        {
            std::string sub;
            iss >> sub;

            if (find(dictionary.begin(),dictionary.end(),sub) != dictionary.end()) {
                found_words += 1;
            }
        } while (iss);
        if (found_words > best_key_matches) {
            best_key = key;
            best_key_matches = found_words;
        }
    }
    return best_key;
}

string to_binary(int number) {
    string binary_number = "";
    while (number > 0) {
        int next_dig = number%2;
        number = number/2;
        string next_char = std::to_string(next_dig);
        binary_number = next_char + binary_number;
    }
    int binary_lenght = binary_number.length();
    string bit_binary_number = "";
    for (int index = 0; index < 8 - binary_lenght; index ++) {
        bit_binary_number += '0';
    }
    bit_binary_number += binary_number;
    return bit_binary_number;
}

string add_bit_binary_numbers (string binary_num_1, string binary_num_2) {
    int index;
    string binary_sum = "";
    for (index = 0; index < 8; index ++) {
        if (binary_num_1[index] == '0' && binary_num_2[index] == '0') {
            binary_sum += "0";
        }
        else if (binary_num_1[index] == '1' && binary_num_2[index] == '0') {
            binary_sum += "1";
        }
        else if (binary_num_1[index] == '0' && binary_num_2[index] == '1') {
            binary_sum += "1";
        }
        else if (binary_num_1[index] == '1' && binary_num_2[index] == '1') {
            binary_sum += "0";
        }
    }
    return binary_sum;
}

char binary_to_char(string binary_num) {
    int number = 0;
    int index;
    for(index = 0; index < binary_num.length(); index++) {
        int value = binary_num[index] - '0';
        if (index == binary_num.length()-1) {
            number += value;
        }
        else {
            number = (number + value)*2;
        }
    }
    return number;
}

vector<string> key_brut_force(void) {
    vector<string> all_keys;
    for(char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                string new_key = "";
                new_key += i;
                new_key += j;
                new_key += k;
                all_keys.push_back (new_key);
            }
        }
    }
    return all_keys;
}
