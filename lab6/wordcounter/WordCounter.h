//
// Created by afghan on 10.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Word.h"
#include "Counts.h"

#include "string"
#include "iostream"
#include "list"
#include <regex>
#include <set>

using std::string;
using std::set;
using std::pair;
using std::list;
using std::initializer_list;

namespace datastructures {

    class WordCounter {

        //POLA KALSY
        list<pair<Word, Counts>> Dictionary;

    public:
        //KONSTRUKTORY
        WordCounter();
        WordCounter(initializer_list<Word>);

        //DESTRUKTOR
        ~WordCounter();

        //OPERATORY
        int operator[](string wanted);

        //METODY
        int DistinctWords();
        int TotalWords();
        set<Word> Words();
    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
