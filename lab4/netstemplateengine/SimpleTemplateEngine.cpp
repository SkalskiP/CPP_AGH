//
// Created by afghan on 21.03.17.
//

#include "SimpleTemplateEngine.h"

namespace nets
{
    View::View(string text)
    {
        wzorzec="";
        for (int i = 0; i < text.size(); ++i) {
            //if(text[i]!='\0')
            {
                wzorzec=wzorzec+text[i];
            }
        }
    }
    string View::Render(const unordered_map <string,string> &model) const
    {
        string wynik="";
        for (int i = 0; i < wzorzec.size(); ++i) {
            //cout<<"b";
            if(i<wzorzec.max_size()-4&&wzorzec[i]=='{'&&wzorzec[i+1]=='{')
            {
                string wzor="";
                //wzor=wzor+wzorzec[i+2];
                int j=i+1;
                bool r=0;
                do
                {
                    j++;
                    //cout<<"a";
                    if(wzorzec[j]=='}'&&wzorzec[j+1]=='}')
                    {
                        //cout<<endl<<wzor;
                        i=j+2;
                        r=1;
                        break;
                    }
                    wzor=wzor+wzorzec[j];
                }while(j<wzorzec.size()-2&&wzorzec[j] <= 'z' && wzorzec[j] >= 'a' || (wzorzec[j] <= 'Z' && wzorzec[j] >= 'A')||wzorzec[j]=='_'||(wzorzec[j] <= '9' && wzorzec[j] >= '0'));

                if(r==1)
                {
                    auto it = model.find(wzor);
                    if (it != model.end())
                    {
                        wzor = it->second;
                        wynik=wynik+wzor;
                    }
                }
            }
            if(i<wzorzec.size())
                wynik=wynik+wzorzec[i];
        }
        //cout<<wynik<<endl<<endl<<endl;
        return wynik;
    }
}