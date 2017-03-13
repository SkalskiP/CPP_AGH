#include "MultiplicationTable.h"
using namespace std;

int main() {
    int tab[10][10];
    MultiplicationTable(tab);
    PrintTable(tab);
    return 0;
}

void PrintTable(int tab[][10]) {
    for(int index_r = 0; index_r < 10; index_r++) {
        for(int index_c = 0; index_c < 10; index_c++) {
            printf("%4d",tab[index_c][index_r]);
        }
        cout << endl;
    }
}

