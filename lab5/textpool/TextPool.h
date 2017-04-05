//
// Created by kornel on 02.04.17.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H
#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <iostream>
using namespace std;

namespace pool
{
    class TextPool
    {
        set <experimental::string_view> s;

        //Rule of Five (z usuniętą możliwością kopiowania)
        //domyślny konstruktor
        //konstruktor z listą inicjalizacyjną
    public:
        TextPool();
        ~TextPool();
        TextPool(const std::initializer_list<experimental::string_view > &elements);
        TextPool(TextPool const & other)=delete;
        TextPool &operator=(TextPool const & other)= delete;
        TextPool(TextPool&& that) ;
        TextPool& operator=(TextPool&& that) noexcept;


        size_t StoredStringCount() const;
        std::experimental::string_view Intern(const std::string &str);
    };
}


using namespace pool;

#endif //JIMP_EXERCISES_TEXTPOOL_H