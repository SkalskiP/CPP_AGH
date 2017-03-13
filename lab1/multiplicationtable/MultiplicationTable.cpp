#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10]) {
    for(int index_r = 0; index_r < 10; index_r++) {
        for(int index_c = 0; index_c < 10; index_c++) {
            tab[index_c][index_r] = (index_c+1)*(index_r+1);
        }
    }
}
