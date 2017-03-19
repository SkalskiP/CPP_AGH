//
// Created by afghan on 16.03.17.
//

#include "SmartTree.h"

using namespace std;
namespace datastructures {

    unique_ptr <SmartTree> CreateLeaf(int value) {
        auto p = make_unique<SmartTree>();
        p -> value = value;
        return p;
    };

    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree) {
        tree -> left = move(left_subtree);
        return tree;
    };
    unique_ptr <SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree) {
        tree -> right = move(right_subtree);
        return tree;
    };

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out){
        if (!unique_ptr) {
            return;
        }
        else {
            PrintTreeInOrder(unique_ptr -> left, out);
            *out << unique_ptr -> value << ", ";
            PrintTreeInOrder(unique_ptr -> right, out);
        }
    };

    string DumpTree(const unique_ptr<SmartTree> &tree) {
        if (!tree) {
            return "[none]";
        }
        else {
            ostringstream ss;
            ss << tree -> value;
            string value = ss.str();
            return "[" + value + " " + DumpTree(tree -> left) + " " + DumpTree(tree -> right) + "]";
        }
    };

    unique_ptr <SmartTree> RestoreTree(const string &tree) {
        unique_ptr <SmartTree> root;
        int i=1,j,k,nawiasy;
        string tonumber="";
        root=CreateLeaf(0);
        while(tree[i]!=' '&&tree[i]!=']')
        {
            tonumber+=tree[i];
            i++;
        }
        if(tonumber=="none")
            return NULL;
        if(tonumber!="none"&&tonumber[0]=='-')
        {
            k=1;
            while (k<tonumber.size())
            {
                root->value=10*root->value+tonumber[k]-'0';
                k++;
            }
            root->value*=-1;
        }
        if(tonumber!="none"&&tonumber[0]!='-')
        {
            k=0;
            while (k<tonumber.size())
            {
                root->value=10*root->value+tonumber[k]-'0';
                k++;
            }
        }
        i+=1;
        j=i;
        nawiasy=1;
        while(nawiasy>0)
        {
            i++;
            if(tree[i]=='[')
                nawiasy++;
            if(tree[i]==']')
                nawiasy--;
        }
        root->left=RestoreTree(tree.substr(j,i-1));
        j=i+2;
        i+=2;
        nawiasy=1;
        while(nawiasy>0)
        {
            i++;
            if(tree[i]=='[')
                nawiasy++;
            if(tree[i]==']')
                nawiasy--;
        }
        root->right=RestoreTree(tree.substr(j,i-1));
        return root;
    };
}
