//
// Created by ravid on 23/05/2021.
//
#pragma once
#ifndef UNTITLED1_BINARYTREE_H
#define UNTITLED1_BINARYTREE_H

#include <glob.h>
#include <iosfwd>

namespace ariel {

    template<typename T>
    class BinaryTree {

    private:
        struct Node {
            T _value;
            Node *_right;
            Node *_left;

            Node(T value) : _value(value), _left(nullptr), _right(nullptr) {};

            ~Node() {
                delete _right;
                delete _left;
            };

        };

        Node *_root;
        size_t _size;
        size_t _depth;

        BinaryTree(const BinaryTree &binaryTree) {};


    public:

        BinaryTree() : _root(nullptr), _size(0), _depth(0) {};

        ~BinaryTree() {
            delete _root;
        };

        BinaryTree<T> &add_root(T value);

        BinaryTree<T> &add_left(T exist_value, T added_value);

        BinaryTree<T> &add_right(T exist_value, T added_value);

        friend std::ostream &operator<<(std::ostream &os, BinaryTree &binaryTree);

        struct Iterator {
        private:
            Node *_cur_node;
            size_t _i;
            size_t _type; // 0 = pre, 1 = in, 2 = post
        public:
            Iterator(Node *node, int type);

            T &operator*() { return _cur_node->_value; }

            T *operator->() { return &(_cur_node->_value); }

            Iterator &operator++();//++i

            const Iterator operator++(int);//i++

            bool operator==(const Iterator &iterator) const;

            bool operator!=(const Iterator &iterator) const;

        };//Iterator

        Iterator begin_preorder() { return Iterator{_root, 0}; };

        Iterator end_preorder() { return Iterator{nullptr, 0}; };

        Iterator begin_inorder() { return Iterator{_root, 1}; };

        Iterator end_inorder() { return Iterator{nullptr, 1}; };

        Iterator begin_postorder() { return Iterator{_root, 2}; };

        Iterator end_postorder() { return Iterator{nullptr, 2}; };

        Iterator begin() { return begin_inorder(); }

        Iterator end() { return end_inorder(); }
    };

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T value) {
        if (_root == nullptr){
            _root = new Node{value};
            ++_size;
        }else{
            _root->_value =value;
        }

        return *this;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T exist_value, T added_value) {


        return *this;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T exist_value, T added_value) {
        return *this;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, BinaryTree<T> &binaryTree) {

        return os;
    }


    template<typename T>
    typename BinaryTree<T>::Iterator &BinaryTree<T>::Iterator::operator++() {

        return *this;
    }

    template<typename T>
    const typename BinaryTree<T>::Iterator BinaryTree<T>::Iterator::operator++(int) {

        return *this;
    }

    template<typename T>
    BinaryTree<T>::Iterator::Iterator(BinaryTree::Node *node, int type):_cur_node(node), _type(type) {
        //TODO
    }

    template<typename T>
    bool BinaryTree<T>::Iterator::operator==(const BinaryTree<T>::Iterator &iterator) const {
        return iterator == _cur_node;
    }

    template<typename T>
    bool BinaryTree<T>::Iterator::operator!=(const BinaryTree<T>::Iterator &iterator) const {
        return iterator != _cur_node;
    }


}
#endif //UNTITLED1_BINARYTREE_H
