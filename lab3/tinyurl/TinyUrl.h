//
// Created by afghan on 14.03.17.
//

#ifndef JIMP_EXERCISES_TINYURL_H
#define JIMP_EXERCISES_TINYURL_H

#include <iostream>
#include <array>
#include <memory>
#include <map>

using namespace std;

namespace tinyurl {

    typedef struct tinyurlcodec {
        array<char, 6> CurrentHash {{'0','0','0','0','0','0'}};
        map <string, string> Mapa;
    } TinyUrlCodec;

    unique_ptr<TinyUrlCodec> Init(void);
    void NextHash(std::array<char, 6> *state);
    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec);
    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash);
}

#endif //JIMP_EXERCISES_TINYURL_H
