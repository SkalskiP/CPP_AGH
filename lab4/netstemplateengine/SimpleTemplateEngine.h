//
// Created by afghan on 21.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
namespace nets
{
    class View
    {
        string wzorzec;
        //unordered_map <string,string> dopasowanie;
    public:
        View(string text);
        string Render(const std::unordered_map <std::string, std::string> &model) const;
    };
}


#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H