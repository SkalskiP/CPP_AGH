//
// Created by afghan on 14.03.17.
//

#include "TinyUrl.h"

using namespace std;
using namespace tinyurl;


int main() {
    array<char, 6> CurrentHash = {'1','z','z','z','z','z'};

    NextHash(&CurrentHash);

    for (auto v : CurrentHash) {
        cout << v;
    }

    return 0;
}