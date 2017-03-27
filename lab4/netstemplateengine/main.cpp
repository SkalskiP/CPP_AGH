//
// Created by afghan on 21.03.17.
//
#include "SimpleTemplateEngine.h"
#include <map>
using namespace std;
using  namespace nets;

int main(){

    View view{"Hello {{name}}! How are you today? My name is {{program}}!"};
    cout << view.GetTekst() << endl;

    unordered_map<string,string> pola;
    pola = {{"name", "Zbigniew"}, {"program", "Borg"}, {"chuj", "Dupa"}};

    cout << view.Render(pola) << endl;

    return 0;
}


