//
// Created by afghan on 22.03.17.
//

#include "SimpleJson.h"

namespace nets
{
    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const
    {
        if(typ!=6)
            return {};
        if(ismap.find(name)!=ismap.end())
        {
            auto it = ismap.find(name);
            if (it != ismap.end())
            {
                return experimental::make_optional(it->second);
            }
        } else
            return {};
    }
    std::string JsonValue::ToString() const
    {
        switch (typ)
        {
            case 1:
            {
                if(isbool==0)
                    return "false";
                else
                    return "true";
            }
            case 2:
            {
                if(isint==0)
                    return  "";
                stringstream w;
                string wynik;
                w<<isint;
                w>>wynik;
                return wynik;
            }
            case 3:
            {
                stringstream w;
                string wynik;
                w<<isdouble;
                w>>wynik;
                return wynik;
            }
            case 4:
            {
                if(isstring=="")
                    return "";
                string wynik;
                for (unsigned long int i = 0; i < isstring.size(); ++i)
                {
                    if(isstring[i]=='\\'||isstring[i]=='\"')
                    {
                        wynik=wynik+"\\";
                    }
                    wynik=wynik+isstring[i];
                }
                return "\""+wynik+"\"";
            }
            case 5:
            {
                string wynik="["+jsonvector[0].ToString();
                for(int i=1;i<jsonvector.size();i++)
                {
                    wynik=wynik+", "+jsonvector[i].ToString();
                }
                wynik=wynik+"]";
                return wynik;
            }
            case 6:
            {
                string wynik="{";
                for(const auto &n:ismap)
                {
                    if(n.first=="")
                        wynik=wynik+""+n.first+": "+""+n.second.ToString()+", ";
                    else
                    {
                        JsonValue wyn{n.first};
                        wynik=wynik+""+wyn.ToString()+": "+""+n.second.ToString()+", ";
                    }
                }
                wynik.pop_back();
                wynik.pop_back();
                wynik=wynik+"}";
                return wynik;
            }
        }
    }

    JsonValue::JsonValue(bool isbool) : isbool(isbool) {this->isbool=isbool;typ=1;}

    JsonValue::JsonValue(int isint) : isint(isint) {this->isint=isint;typ=2;}

    JsonValue::JsonValue(double isdouble) : isdouble(isdouble) {this->isdouble=isdouble;typ=3;}

    JsonValue::JsonValue(const string &isstring) : isstring(isstring) {this->isstring=isstring;typ=4;}

    JsonValue::JsonValue(const vector<JsonValue> &jsonvector) : jsonvector(jsonvector) {this->jsonvector=jsonvector;typ=5;}

    JsonValue::JsonValue(const map<string, JsonValue> &ismap) : ismap(ismap) {this->ismap=ismap;typ=6;}

}