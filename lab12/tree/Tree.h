//
// Created by afghan on 11.06.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <vector>
#include <memory>
#include <stack>
namespace tree {

    template <class T>
    class Tree {
    public:
        Tree(const T& element = T()) : data{element}, left{nullptr}, right{nullptr} {}
        void Insert(const T &element);
        //T Search(const T &value);
        bool Find(const T &value);
        std::shared_ptr<T> Search(const T &value);
        size_t Size();
        size_t Depth();

        //std::unique_ptr<Node<T>> root;
        std::unique_ptr<Tree<T>> left;
        std::unique_ptr<Tree<T>> right;

        T Value() const {return data;}
        Tree<T>* Root() {return this;}

        T data;
    };

    //TREE

    template <class T>
    void Tree<T>::Insert(const T &element) {
        std::unique_ptr<Tree<T>> new_node = std::make_unique<Tree<T>>(Tree<T>(element));
        auto p = this;
        while (p) {
            if (element < p->data) {
                if (p->left) {
                    p = p->left.get();
                } else {
                    p->left = std::move(new_node);
                    break;
                }
            } else {
                if (p->right) {
                    p = p->right.get();
                } else {
                    p->right = std::move(new_node);
                    break;
                }
            }
        }
    }

    template<class T>
    std::shared_ptr<T> Tree<T>::Search(const T &value) {
        auto node = this;
        while (node) {
            if (node->data == value) {
                return std::make_shared<T>(node->data);
            }
            if (value < node->data) {
                node = node->left.get();
            } else {
                node = node->right.get();
            }
        }
        return nullptr;
    }

    template<class T>
    bool Tree<T>::Find(const T &value) {
        return (Search(value) != nullptr);
    }

    template <class T>
    size_t Tree<T>::Depth() {
        size_t left_d=0, right_d=0;
        if (left) left_d=left->Depth();
        if (right) right_d=right->Depth();
        if (left_d > right_d)
            return ++left_d;
        return ++right_d;
    }

    template <class T>
    size_t Tree<T>::Size() {
        size_t size = 1;
        if (left) size += left->Size();
        if (right) size += right->Size();
        return size;
    }
}


#endif //JIMP_EXERCISES_TREE_H
