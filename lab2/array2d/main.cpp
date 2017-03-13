#include "Array2D.h"
using namespace std;

int main() {
    int n_rows, n_columns; // Zmienne przechowujace ilosc wierszy oraz kolumn
    int **p; // Wskaznik do tablicy dwu-wymiarowej
    cout << "Podaj ilosc wierszy: ";
    cin >> n_rows;
    cout << "Podaj ilosc kolumn: ";
    cin >> n_columns;
    p = Array2D(n_rows, n_columns);
    DeleteArray2D(p, n_rows, n_columns);
    return 0;
}