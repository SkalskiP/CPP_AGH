//
// Created by afghan on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <iostream>
#include <complex>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

namespace algebra {

    class Matrix {

        int d_row;
        int d_col;
        vector<vector<std::complex<double>>> matrix;

    public:

        Matrix(int, int);
        Matrix(const std::initializer_list<std::vector<std::complex<double> > >& list);
        Matrix(const algebra::Matrix&);
        Matrix();

        pair<long unsigned int, long unsigned int> Size();
        string Print() const;
        algebra::Matrix Mul(const algebra::Matrix) const;
        algebra::Matrix Add(const algebra::Matrix) const;
        algebra::Matrix Sub(const algebra::Matrix) const;
        algebra::Matrix Pow(int);

    };

}

#endif //JIMP_EXERCISES_MATRIX_H
