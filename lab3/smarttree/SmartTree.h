//
// Created by afghan on 16.03.17.
//

#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;
namespace datastructures {
    typedef struct tree {
        int value;
        unique_ptr<tree> left = nullptr;
        unique_ptr<tree> right = nullptr;
    } SmartTree;

    unique_ptr <SmartTree> CreateLeaf(int value);
    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree);
    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    unique_ptr <SmartTree> RestoreTree(const string &tree);
}

#endif //JIMP_EXERCISES_SMARTTREE_H
