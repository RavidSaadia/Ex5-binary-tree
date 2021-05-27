//
// Created by ravid on 23/05/2021.
//
#pragma once
#ifndef UNTITLED1_BINARYTREE_H
#define UNTITLED1_BINARYTREE_H

#include <glob.h>
#include <iosfwd>
#include <vector>
#include <iostream>

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

        };//NODE
    private:
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

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &binaryTree) {


            return os;
        }

        struct Iterator {
        private:
            Node *_cur_node;
            std::vector<Node *> _arr;
            size_t _i = 0;
            size_t _type; // 0 = pre, 1 = in, 2 = post
        public:
            Iterator(Node *node, size_t type);

            const T &operator*() { return _cur_node->_value; }

            const T *operator->() { return &(_cur_node->_value); }

            Iterator &operator++();//++i

            const Iterator operator++(int);//i++

            bool operator==(const Iterator &iterator) const;

            bool operator!=(const Iterator &iterator) const;

            void fill_preOrder(std::vector<Node *> &arr, BinaryTree::Node **root);

            void fill_inOrder(std::vector<Node *> &arr, BinaryTree::Node **root);

            void fill_postOrder(std::vector<Node *> &arr, BinaryTree::Node **root);
        };//Iterator

        Node *search_in_tree(BinaryTree<T>::Node *n, T value);

        Iterator begin_preorder() { return Iterator{_root, 0}; };

        Iterator end_preorder() { return Iterator{nullptr, 0}; };

        Iterator begin_inorder() { return Iterator{_root, 1}; };

        Iterator end_inorder() { return Iterator{nullptr, 1}; };

        Iterator begin_postorder() { return Iterator{_root, 2}; };

        Iterator end_postorder() { return Iterator{nullptr, 2}; };

        Iterator begin() { return begin_inorder(); }

        Iterator end() { return end_inorder(); }
    };//Binary tree

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T value) {
        if (_root == nullptr) {
            _root = new Node{value};
            ++_size;
        } else {
            _root->_value = value;
        }

        return *this;
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_left(T exist_value, T added_value) {

        Node *p = search_in_tree(_root, exist_value);
        if (p == nullptr) {
            throw;
        }
        if (p->_left == nullptr) {
            p->_left = new Node{added_value};
            return *this;
        } else {
            p->_left->_value = added_value;
            return *this;
        }
    }

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_right(T exist_value, T added_value) {
        Node *p = search_in_tree(_root, exist_value);
        if (p == nullptr) {
            throw;
        }
        if (p->_right == nullptr) {
            p->_right = new Node{added_value};
            return *this;
        } else {
            p->_right->_value = added_value;
            return *this;
        }
    }

//    template<typename T>
//    std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &binaryTree) {
//
//        return os;
//    }


    template<typename T>
    typename BinaryTree<T>::Iterator &BinaryTree<T>::Iterator::operator++() {
//        this->_cur_node = _cur_node->_right;
        _i++;
        _cur_node = _arr[_i];
        return *this;
    }

    template<typename T>
    const typename BinaryTree<T>::Iterator BinaryTree<T>::Iterator::operator++(int) {
        BinaryTree<T>::Iterator temp = this;
        _i++;
        _cur_node = _arr[_i];
        return temp;
    }

    // CONSTRUCTOR
    template<typename T>
    BinaryTree<T>::Iterator::Iterator(BinaryTree::Node *node, size_t type):_cur_node(node), _type(type), _i(0) {
        switch (_type) {
            case 0: {
                fill_preOrder(_arr, &_cur_node);
                if (_cur_node) {
                    _cur_node = _arr[0];
                }
                break;
            }
            case 1: {
                fill_inOrder(_arr, &_cur_node);
                if (_cur_node) {
                    _cur_node = _arr[0];
                }

                break;
            }
            case 2: {
                fill_postOrder(_arr, &_cur_node);
                if (_cur_node) {
                    _cur_node = _arr[0];
                }

                break;
            }
            default:
                std::cout << "the type is not cool!";
        }

    }

    template<typename T>
    bool BinaryTree<T>::Iterator::operator==(const BinaryTree<T>::Iterator &iterator) const {
        return _cur_node == iterator._cur_node;
    }

    template<typename T>
    bool ariel::BinaryTree<T>::Iterator::operator!=(const ariel::BinaryTree<T>::Iterator &iterator) const {
        return _cur_node != iterator._cur_node;
    }

    template<typename T>
    void BinaryTree<T>::Iterator::fill_preOrder(std::vector<Node *> &arr, BinaryTree::Node **root) {
        if (*root == nullptr) {
            return;
        }
        arr.push_back(*root);
        fill_preOrder(arr, &(*root)->_left);
        fill_preOrder(arr, &(*root)->_right);
    }

    template<typename T>
    void BinaryTree<T>::Iterator::fill_inOrder(std::vector<Node *> &arr, BinaryTree::Node **root) {

        if (*root == nullptr) {
            return;
        }
        fill_inOrder(arr, &(*root)->_left);
        arr.push_back(*root);
        fill_inOrder(arr, &(*root)->_right);
    }

    template<typename T>
    void BinaryTree<T>::Iterator::fill_postOrder(std::vector<Node *> &arr, BinaryTree::Node **root) {
        if (*root == nullptr) {
            return;
        }
        fill_postOrder(arr, &(*root)->_left);
        fill_postOrder(arr, &(*root)->_right);
        arr.push_back(*root);
    }

    // inspired by Geeks for Geeks
    template<typename T>
    typename BinaryTree<T>::Node *BinaryTree<T>::search_in_tree(BinaryTree<T>::Node *n, T value) {

        if (n == nullptr) {
            return nullptr;
        }
        if (n->_value == value) {
            return n;
        }
        Node *ans1 = search_in_tree(n->_left, value);
        if (ans1 != nullptr) {
            return ans1;
        }
        Node *ans2 = search_in_tree(n->_right, value);
        if (ans2 != nullptr) {
            return ans2;
        }
        return ans2;
    }

}//ariel
#endif //UNTITLED1_BINARYTREE_H
