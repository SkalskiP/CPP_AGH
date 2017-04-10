//
// Created by afghan on 10.04.17.
//

#include "Counts.h"
using namespace datastructures;
using namespace std;

//KONSTRUKTORY
Counts::Counts() {
}

Counts::Counts(int number) {
    Counter = number;
}

//DESTRUKTOR
Counts::~Counts() {
}

//OPERATORY
Counts & Counts::operator++() {
    Counter++;
    return *this;
}

bool Counts::operator<(Counts argument) const {
    return (Counter<argument.Counter);
}

bool Counts::operator>(Counts argument) const {
    return (Counter>argument.Counter);
}

bool Counts::operator==(Counts argument) const {
    return (Counter==argument.Counter);
}
