#include "CCounter.h"

using namespace std;

namespace ccounter {

    unique_ptr<Counter> Init(void) {
        auto p = make_unique<Counter>();
        return p;
    };

    void Inc(string key, unique_ptr<Counter> * counter) {
        if ( (*counter)->mapa.find(key) == (*counter)->mapa.end() ) {
            (*counter)->mapa[key] = 1;
        } else {
            (*counter)->mapa[key] ++;
        }
    };

    int Counts(unique_ptr<Counter> &counter, string key) {
        if ( counter->mapa.find(key) == counter->mapa.end() ) {
            return 0;
        } else {
            return (counter->mapa[key]);
        }
    };

    void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter) {
        (*counter)->mapa[key] = value;
    };
}


