//
// Created by afghan on 14.03.17.
//

#ifndef JIMP_EXERCISES_CCOUNTER_H
#define JIMP_EXERCISES_CCOUNTER_H

#include <iostream>
#include <memory>
#include <map>

using namespace std;

namespace ccounter {
    typedef struct counter {
        map <string, int> mapa;
    } Counter;

    unique_ptr<Counter> Init(void);
    void Inc(string key, unique_ptr<Counter> * counter);
    int Counts(unique_ptr<Counter> &counter, string key);
    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);
}

#endif //JIMP_EXERCISES_CCOUNTER_H
