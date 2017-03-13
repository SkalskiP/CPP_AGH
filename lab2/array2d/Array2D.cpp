#include "Array2D.h"

int **Array2D(int n_rows, int n_columns) {
    if (n_rows <= 0 || n_columns <= 0) {
        return NULL;
    }
    int **p = new int*[n_rows]; // Wskaznik do tablicy wskaznikow

    for(int index = 0; index < n_rows; index++)
    {
        p[index] = new int[n_columns]; // Allokowanie pamieci dla wektora o wielkosci jednego wiersza
    }
    FillArray2D(p, n_rows, n_columns);
    return p;

}

void DeleteArray2D(int **array, int n_rows, int n_columns) {
    for(int index = 0; index < n_rows; index++)
    {
        delete[] array[index];
    }
    delete [] array;
}

//Test dwa
/*void FillArray2D(int **array, int n_rows, int n_columns) {
    for(int index = 0; index < n_rows; index++) {
        for(int index_wew = 0; index_wew < n_columns; index_wew++) {
            array[index][index_wew] = (index+1)*(index_wew+1);
        }
    }
}*/

//Test jeden
void FillArray2D(int **array, int n_rows, int n_columns) {
    for(int index = 0; index < n_rows; index++) {
        for(int index_wew = 0; index_wew < n_columns; index_wew++) {
            array[index][index_wew] = index*n_columns + (index_wew+1);
        }
    }
}