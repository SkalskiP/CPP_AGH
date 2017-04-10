//
// Created by afghan on 10.04.17.
//

#include "Word.h"
using namespace datastructures;
using namespace std;

//KONSTRUKTORY
Word::Word() {
}

Word::Word(string value) {
    Value = value;
}

//DESTRUKTOR
Word::~Word() {
}

//OPERATORY
bool Word::operator<(Word argument) const {
    return (Value<argument.Value);
}

bool Word::operator==(Word argument) const {
    return (Value==argument.Value);
}
