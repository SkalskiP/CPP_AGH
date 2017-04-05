//
// Created by afghan on 03.04.17.
//

#include <iostream>
#include "Matrix.h"
using namespace std;
using namespace algebra;

int main() {
/*
    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};
    Matrix m2{{7. + 1.0i, 0., 0.}, {0., 1.0i, 8.}, {15. + 2.0i, 0. + 3.0i, 4. + 1.0i}};
    cout << m1.Print() << endl;
    cout << m2.Print() << endl;
    cout << m1.Sub(m2).Print() << endl;


    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
    Matrix m2{{7. + 1.0i, 0.}, {0., 1.0i}, {15. + 2.0i, 0. + 3.0i}};
    //Matrix m3{3, 4};
    cout << m1.Print() << endl;
    cout << m2.Print() << endl;
    //cout << m3.Print() << endl;
    cout << m1.Mul(m2).Print() << endl;


    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}};
    Matrix m2{{7. + 1.0i, 0.}, {0., 1.0i}, {15. + 2.0i, 0. + 3.0i}};
    cout << m1.Mul(m2).Print() << endl;
*/
    Matrix pauli{{0.0, 0.0 - 1.0i}, {1.0i, 0.0}};
    cout << pauli.Pow(2).Print() << endl;
    return 0;
}