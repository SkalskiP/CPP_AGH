//
// Created by afghan on 14.03.17.
//

#include "TinyUrl.h"

using namespace std;

namespace tinyurl {

    unique_ptr<TinyUrlCodec> Init(void) {
        auto p = make_unique<TinyUrlCodec>();
        return p;
    };

    void NextHash(array<char, 6> *state) {

        for (int i = (*state).size(); i --> 0; )
        {
            (*state)[i] += 1;
            if ((*state)[i] == '9' + 1) {
                (*state)[i] = 'A';
            }
            else if ((*state)[i] == 'Z' + 1) {
                (*state)[i] = 'a';
            }
            else if ((*state)[i] == 'z' + 1) {
                (*state)[i] = '0';
            }

            if ((*state)[i] != '0') {
                break;
            }
        }
    };

    string Encode(const string &url, unique_ptr<TinyUrlCodec> *codec) {
        if ( (*codec)->Mapa.find(url) == (*codec)->Mapa.end() ) {
            string str(std::begin((*codec) -> CurrentHash), std::end((*codec) -> CurrentHash));
            NextHash(&((*codec) -> CurrentHash));
            (*codec)->Mapa[str] = url;
            return str;

        } else {
            return ((*codec)->Mapa[url]);
        }
    };

    string Decode(const unique_ptr<TinyUrlCodec> &codec, const string &hash) {
        if ( codec->Mapa.find(hash) == codec->Mapa.end() ) {
            return NULL;

        } else {
            return (codec->Mapa[hash]);
        }
    };
}