//
// Created by afghan on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include "iostream"
#include "string"
using namespace std;

namespace datastructures {

    class Word {
        friend class WordCounter;

        //POLA KLASY
        string Value; //zatrzymuje slowo

    public:
        //KONSTRUKTORY
        Word();
        Word(string str);

        //DESTRUKTOR
        ~Word();

        //OPERATORY
        bool operator<(Word) const;
        bool operator==(Word) const;
    };

}

#endif //JIMP_EXERCISES_WORD_H
