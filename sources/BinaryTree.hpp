//
// Created by ravid on 23/05/2021.
//

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

        size_t _size;
        Node *_root;


    public:
        BinaryTree(const BinaryTree &binaryTree) {};

        BinaryTree() : _root(nullptr), _size(0) {};

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
            size_t i;
            size_t type;
        public:
            T& operator*(){
                return _cur_node->_value;
            }
            T& operator->(){ // *T?
                return &(_cur_node->_value);
            }
            bool operator==(const Iterator &iterator)const{
                return iterator == _cur_node;
            };


            bool operator!=(const Iterator &iterator){
                return iterator != _cur_node;
            };


            Iterator& operator++();//++i


            const Iterator operator++(int);//i++


        };//Iterator

        Iterator begin_preorder();
    };

    template<typename T>
    BinaryTree<T> &BinaryTree<T>::add_root(T value) {

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
    BinaryTree::Iterator BinaryTree<T>::begin_preorder() {
        return BinaryTree::Iterator();
    }

    template<typename T>
     typename BinaryTree<T>::Iterator &BinaryTree<T>::Iterator::operator++() {

        return *this;
    }
    template<typename T>
    const typename BinaryTree<T>::Iterator BinaryTree<T>::Iterator::operator++(int) {

        return *this;
    }

}
#endif //UNTITLED1_BINARYTREE_H
