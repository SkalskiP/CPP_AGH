//
// Created by afghan on 10.04.17.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

#include "iostream"
using namespace std;

namespace datastructures {

    class Counts {
        friend class WordCounter;

        //POLA KLASY
        int Counter; //zatrzymuje ilosc wystapien slowa

    public:
        //KONSTRUKTORY
        Counts();
        Counts(int);

        //DESTRUKTOR
        ~Counts();

        //OPERATORY
        Counts & operator++();
        bool operator<(Counts) const;
        bool operator>(Counts) const;
        bool operator==(Counts) const;
    };
}

#endif //JIMP_EXERCISES_COUNTS_H
