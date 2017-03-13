//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
  int fact = 1, iteration;
    if (value > 0) {
        for(iteration = 1; iteration <= value; iteration++) {
            fact = fact*iteration;
        }
    }
    else if (value < 0) {
        for(iteration = -1; iteration >= value; iteration--) {
            fact = fact*iteration;
        }
    }
    return fact;
}
