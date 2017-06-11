//
// Created by afghan on 30.05.17.
//

#include "tree.h"
using namespace std;

int main() {

    Tree<int> Drzewo;
    Drzewo.Add(1);
    Drzewo.Add(10);
    Drzewo.Add(7);
    Drzewo.Add(5);
    Drzewo.Add(15);

    cout << Drzewo.Search(8) << endl;
    //cout << Drzewo.root->left->left->value << endl;

    return 0;
};