//
// Created by afghan on 30.05.17.
//

#ifndef JIMP_EXERCISES_NODE_H
#define JIMP_EXERCISES_NODE_H

#include <iostream>
using namespace std;

template<class T>

class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T Value) {
        left = NULL;
        right = NULL;
        value = Value;
    }
};

#endif //JIMP_EXERCISES_NODE_H
