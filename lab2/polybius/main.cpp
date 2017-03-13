#include "Polybius.h"
using namespace std;

int main(int argv, char **argc) {

    ifstream plik_odczyt(argc[1]);
    string line;

    fstream plik_zapis;
    plik_zapis.open(argc[2], ios_base::out);

    while(!plik_odczyt.eof()){
        getline(plik_odczyt, line);
        plik_zapis << PolybiusCrypt(line) << endl;
    }

    plik_odczyt.close();
    plik_zapis.close();
    return 0;
}

