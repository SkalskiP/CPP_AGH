//
// Created by afghan on 03.04.17.
//
#include <iostream>
#include "Matrix.h"
using namespace std;

namespace algebra {

    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double> > >& list) : d_row(list.size()), d_col((*list.begin()).size()) {
        matrix.reserve(d_row);

        for (const auto& l : list) {
            matrix.emplace_back(l);
        }
    }

    Matrix::Matrix(int col, int row) {

        d_col = col;
        d_row = row;
        matrix.reserve(d_row);

        for (int i = 0; i < d_row; i ++) {
            for (int j = 0; j < d_col; j ++) {

                matrix[i].push_back(complex<double>(0,0));

            }
        }
    }

    Matrix::Matrix(){
        d_col=0;
        d_row=0;
    }

    Matrix::Matrix(const algebra::Matrix& argument) {
        this->matrix = argument.matrix;
        this->d_col = argument.d_col;
        this->d_row = argument.d_row;
    }

    string Matrix::Print() const{
        std::ostringstream output;
        output << "[";

        for(int i = 0; i < d_row; i++) {
            for(int j = 0; j < d_col; j++) {
                output << std::real(matrix[i][j]) << "i" << std::imag(matrix[i][j]);

                if (j == d_col-1 && i != d_row-1) {
                    output << "; ";
                }
                else if (i != d_row-1 || j != d_col-1) {
                    output << ", ";
                }
            }
        }

        output << "]";
        return output.str();

    }

    algebra::Matrix Matrix::Add(const algebra::Matrix other) const{
        algebra::Matrix wynik = *this;

        for(int i = 0; i < d_row; i++) {
            for(int j = 0; j < d_col; j++) {
                //double real = std::real(this->matrix[i][j]) + std::real(other.matrix[i][j]);
                //double imag = std::imag(this->matrix[i][j]) + std::imag(other.matrix[i][j]);
                //wynik.matrix[i][j] = std::complex<double>(real, imag);

                wynik.matrix[i][j] = (this->matrix[i][j]) + (other.matrix[i][j]);
            }
        }
        return wynik;
    }

    algebra::Matrix Matrix::Sub(const algebra::Matrix other) const{
        algebra::Matrix wynik = *this;

        for(int i = 0; i < d_row; i++) {
            for(int j = 0; j < d_col; j++) {
                //double real = std::real(this->matrix[i][j]) - std::real(other.matrix[i][j]);
                //double imag = std::imag(this->matrix[i][j]) - std::imag(other.matrix[i][j]);
                //wynik.matrix[i][j] = std::complex<double>(real, imag);

                wynik.matrix[i][j] = (this->matrix[i][j]) - (other.matrix[i][j]);
            }
        }
        return wynik;
    }

    algebra::Matrix Matrix::Mul(const algebra::Matrix other) const {

        algebra::Matrix wynik;

        if (this->d_col != other.d_row) {
            wynik.d_col = 0;
            wynik.d_row = 0;
            return wynik;
        }

        wynik.d_col = other.d_col;
        wynik.d_row = this->d_row;

        vector <std::complex<double>> a;

        for (int i = 0; i < this->d_row; i ++)
        {
            a.clear();
            for (int j = 0; j < other.d_col; j ++) {

                a.push_back(complex<double>(0,0));
            }

            wynik.matrix.push_back(a);
        }
        for(int i = 0; i < wynik.d_row; i++) {
            for(int j = 0; j < wynik.d_col; j++) {
                std::complex<double> new_val(0, 0);
                for(int k = 0; k < this->d_col; k++) {
                    new_val += (this->matrix[i][k]) * (other.matrix[k][j]);
                }
                //cout << real(new_val) << " " << imag(new_val) << endl;
                wynik.matrix[i][j] = new_val;

            }
        }
        return wynik;
    }

    algebra::Matrix Matrix::Pow(int power) {
        algebra::Matrix wynik;

        if (d_col == d_row) {
            wynik = *this;

            if (power == 1) {
                return wynik;
            }
            else if (power == 0) {

                for(int i = 0; i < wynik.d_row; i++) {
                    for(int j = 0; j < wynik.d_col; j++) {

                        if (i == j) {
                            wynik.matrix[i][j] = complex<double>(1, 0);
                        }
                        else {
                            wynik.matrix[i][j] = complex<double>(0, 0);
                        }

                    }
                }
                return wynik;
            }
            else if (power > 1) {
                for(int i = 2; i <= power; i ++) {
                    wynik = wynik.Mul(*this);
                }
                return wynik;
            }

        }
        else {
            wynik = Matrix();
            return wynik;
        }
    };

    pair<long unsigned int, long unsigned int> Matrix::Size() {

        return pair<long unsigned int, long unsigned int>(d_row, d_col);
    };

}
