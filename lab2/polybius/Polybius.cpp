#include "Polybius.h"
using namespace std;

string PolybiusCrypt(string message) {
    string encrypted = "";
    int index;
    for(index = 0; index < message.length(); index++) {
        int character_number = 0;
        if (message[index] >= 'a' && message[index] <= 'i') {
            character_number = message[index] - 'a' + 1;
        }
        else if (message[index] >= 'j' && message[index] <= 'z') {
            character_number = message[index] - 'a';
        }
        else if (message[index] >= 'A' && message[index] <= 'I') {
            character_number = message[index] - 'A' + 1;
        }
        else if (message[index] >= 'J' && message[index] <= 'Z') {
            character_number = message[index] - 'A';
        }

        if (character_number > 0) {
            int r_number = character_number/5 + 1;
            int c_number = character_number%5;

            if (c_number == 0) {
                c_number = 5;
                r_number -= 1;
            }
            cout << "litera " << message[index] << " o numerze " << message[index] - 'a' + 1 << " zostala zamieniona na " << r_number << " " << c_number << endl;
            encrypted += '0' + r_number;
            encrypted += '0' + c_number;
        }
    }
    return encrypted;
}

string PolybiusDecrypt(string crypted) {
    string decrypted = "";

    int index;
    for(index = 0; index < crypted.length(); index += 2) {
        int r_number = crypted[index] - '0';
        int c_number = crypted[index+1] - '0';
        char character = (r_number-1)*5+c_number + 'a' - 1;
        if (character > 'i') {
            character += 1;
        }
        decrypted += character;
    }

    return decrypted;
}
