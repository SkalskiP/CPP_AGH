//
// Created by afghan on 22.03.17.
//

#ifndef JIMP_EXERCISES_JSONVALUE_H
#define JIMP_EXERCISES_JSONVALUE_H
#include <experimental/optional>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

namespace nets
{
    class JsonValue {
    private:
        int typ;
        bool isbool;
        int isint;
        double isdouble;
        string isstring;
        vector <JsonValue> jsonvector;
        map <string,JsonValue> ismap;
    public:
        JsonValue(bool isbool);

        JsonValue(int isint);

        JsonValue(double isdouble);

        JsonValue(const string &isstring);

        JsonValue(const vector<JsonValue> &jsonvector);

        JsonValue(const map<string, JsonValue> &ismap);


    public:
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    };
}
using namespace nets;

#endif //JIMP_EXERCISES_JSONVALUE_H