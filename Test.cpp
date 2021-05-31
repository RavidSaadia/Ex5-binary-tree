//
// Created by ravid on 24/05/2021.
//

#include <stdlib.h>
#include "doctest.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

#include "BinaryTree.hpp"

using namespace ariel;

TEST_CASE ("Test Basic Tree ")
{

    BinaryTree<int> tree_of_ints;
            CHECK_NOTHROW(tree_of_ints.add_root(1));
            CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
            CHECK_NOTHROW(tree_of_ints.add_left(9, 4));
            CHECK_NOTHROW(tree_of_ints.add_right(9, 5));
            CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
            CHECK_NOTHROW(tree_of_ints.add_left(1, 2));
            CHECK_NOTHROW(tree_of_ints.add_left(3, 8));
            CHECK_NOTHROW(tree_of_ints.add_right(3, 7));

    /********** Changing State To: **************
      *                                          * └──1
      *                 1                        *  ├──3
      *               /   \                      *  │ ├──7
      *             2       3                    *  │ └──8
      *            / \     /  \                  *  └──2
      *           4   5   8    7                 *    ├──5
      *                                          *    └──4
      ********************************************
  */







            SUBCASE("printing") {
        cout << tree_of_ints << endl;
    }


}

TEST_CASE ("add root") {
    BinaryTree<int> int_tree;
    for (int i = 0; i < 10; ++i) {
        int root = rand();
                CHECK_NOTHROW(int_tree.add_root(root));
                CHECK_EQ(*int_tree.begin_inorder(), root);
                CHECK_EQ(*int_tree.begin_postorder(), root);
                CHECK_EQ(*int_tree.begin_preorder(), root);

    }
}

TEST_CASE ("add right") {
    BinaryTree<int> int_tree;
    for (int i = 0; i < 10; ++i) {
        int root = rand();
        int right = rand();
                CHECK_NOTHROW(int_tree.add_root(root));
                CHECK_NOTHROW(int_tree.add_left(root, right));
                CHECK_EQ(*(int_tree.begin_inorder()), right);
                CHECK_EQ(*int_tree.begin_postorder(), right);
                CHECK_EQ(*int_tree.begin_preorder(), root);

    }
    //    //   tree with only lefts sun`s from 0 to 10
    int_tree.add_root(0);
    for (int i = 0; i < 10; ++i) {
        int_tree.add_right(i, i + 1);
    }
    int i = 10; // compere int

            SUBCASE("post") {
        for (auto it = int_tree.begin_postorder(); it != int_tree.end_postorder(); ++it) {
                    CHECK_EQ(*it, i--);
        }

    }
            SUBCASE("pre") {

        i = 10;
        for (auto it = int_tree.begin_preorder(); it != int_tree.end_preorder(); ++it) {
                    CHECK_EQ(*it, i--);
        }
    }
            SUBCASE("in") {

        i = 0;
        for (auto it = int_tree.begin_inorder(); it != int_tree.end_inorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }
    }
}

TEST_CASE ("add left") {
    BinaryTree<int> int_tree;
    for (int i = 0; i < 10; ++i) {
        int root = rand();
        int left = rand();
                CHECK_NOTHROW(int_tree.add_root(root));
                CHECK_NOTHROW(int_tree.add_left(root, left));
                CHECK_EQ(*(int_tree.begin_inorder()), left);
                CHECK_EQ(*int_tree.begin_postorder(), left);
                CHECK_EQ(*int_tree.begin_preorder(), root);

    }
}


