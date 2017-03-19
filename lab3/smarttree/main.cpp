//
// Created by afghan on 16.03.17.
//

#include "SmartTree.h"

using namespace std;
using namespace datastructures;

int main() {
    unique_ptr<SmartTree> root = CreateLeaf(27);
    unique_ptr<SmartTree> child = CreateLeaf(55);
    cout << root -> value << endl;
    cout << child -> value << endl;
    unique_ptr<SmartTree> new_root = InsertLeftChild(move(root), move(child));
    cout << new_root -> left -> value << endl;
    return 0;
}