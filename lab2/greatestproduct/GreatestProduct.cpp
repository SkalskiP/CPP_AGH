//
// Created by afghan on 08.03.17.
//

#include "GreatestProduct.h"
using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k) {

    vector<int> big;
    vector<int> small;

    for (int index = 0; index < numbers.size(); index++) {

        if (big.size() < k) {
            big.push_back(numbers[index]);
        }
        else if (big[minimum_index(big)] < numbers[index]) {
            big[minimum_index(big)] = numbers[index];
        }

        if (small.size() < k) {
            small.push_back(numbers[index]);
        }
        else if (small[maximum_index(small)] > numbers[index]) {
            small[maximum_index(small)] = numbers[index];
        }
    }

    sort (big.begin(), big.end(), my_max);
    sort (small.begin(), small.end(), my_min);

    int max_i = 0; // index vectora duzych liczb
    int min_i = 0; // index vectora malych liczb
    int product_i = 0; // ilosc liczb wliczonych do iloczynu
    int product = 1; // zmienna zapisujaca wartosc iloczynu

    while (product_i < k) { // jezeli iloczyn jest wynikiem pomnozenia mniej niz k liczb

        if (k - product_i > 1 ) { //jezeli do iloczynu musimy dodac co najmniej 2 liczby
            if (big[max_i] * big[max_i + 1] <= small[min_i] * small[min_i + 1]){
                // iloczyn dwoch najmniejszych liczb jest wiekszy od iloczynu dwoch najwiekszych
                product *= small[min_i] * small[min_i + 1]; //iloczyn mnozymy przez dwie najmniejsze liczby
                min_i += 2; // licznik najmniejszych liczb rosnie o dwa
            }
            else {
                product *= big[max_i]; // iloczyn mnozymy przez najwiesza liczbe
                max_i += 1; //licznik najwiekszych liczb rosnie o jeden
            }
        }
        else if (k - product_i == 1 ) { //jezeli do iloczynu musimy dodac jeszcze jedna liczbe
            if (big.size() - max_i >= 1) {
                product *= big[max_i];
                max_i += 1;
            }
            else {
                product *= small[min_i];
                min_i += 1;
            }
        }
        product_i = min_i + max_i;
    }

    int product_max = 1; //iloczyn wszystkich najmniejszych liczb [na wypadek gdyby byly tylko ujemne]
    for(product_i = 0; product_i < k; product_i ++) {
        product_max *= big[product_i];
    }
    return max(product, product_max);
}

int minimum_index (vector<int> numbers) {
    int min_index = 0;
    int min_val = numbers[0];
    for (int index = 1; index < numbers.size(); index ++) {
        if (min_val > numbers[index]) {
            min_val = numbers[index];
            min_index = index;
        }
    }
    return min_index;
}

int maximum_index (vector<int> numbers) {
    int max_index = 0;
    int max_val = numbers[0];
    for (int index = 1; index < numbers.size(); index ++) {
        if (max_val < numbers[index]) {
            max_val = numbers[index];
            max_index = index;
        }
    }
    return max_index;
}

bool my_max (int i,int j) { return (i>j); }
bool my_min (int i,int j) { return (i<j); }