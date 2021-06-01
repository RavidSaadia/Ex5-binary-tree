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

TEST_CASE ("int tree") {
            SUBCASE ("add root") {
        BinaryTree<int> int_tree;
        for (int i = 0; i < 10; ++i) {
            int root = rand();
                    CHECK_NOTHROW(int_tree.add_root(root));
                    CHECK_EQ(*int_tree.begin_inorder(), root);
                    CHECK_EQ(*int_tree.begin_postorder(), root);
                    CHECK_EQ(*int_tree.begin_preorder(), root);

        }
    }

            SUBCASE ("add right") {
        BinaryTree<int> t1;
        for (int i = 0; i < 10; ++i) {
            int root = rand();
            int right = rand();
                    CHECK_NOTHROW(t1.add_root(root));
                    CHECK_NOTHROW(t1.add_left(root, right));
                    CHECK_EQ(*(t1.begin_inorder()), right);
                    CHECK_EQ(*t1.begin_postorder(), right);
                    CHECK_EQ(*t1.begin_preorder(), root);

        }
        //    //   tree with only right sun`s from 0 to 10
        // root-> 0
        //         \
    //          1-2-3-4-5-6-7-8-9-10

        BinaryTree<int> t2;
        t2.add_root(0);
        for (int i = 0; i < 10; ++i) {
            t2.add_right(i, i + 1);
        }
        int i = 10; // compere int
        for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
                    CHECK_EQ(*it, i--);
        }

        //post
        i = 0;
        for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }

        //in
        i = 0;
        for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }

    }

            SUBCASE ("add left") {
        BinaryTree<int> t1;
        for (int i = 0; i < 10; ++i) {
            int root = rand();
            int left = rand();
                    CHECK_NOTHROW(t1.add_root(root));
                    CHECK_NOTHROW(t1.add_left(root, left));
                    CHECK_EQ(*(t1.begin_inorder()), left);
                    CHECK_EQ(*t1.begin_postorder(), left);
                    CHECK_EQ(*t1.begin_preorder(), root);

        }
        //    //   tree with only left sun`s from 0 to 10
        //               root-> 0
        //                     /
        // 10-9-8-7-6-5-4-3-2-1

        int i = 10; // compere int
        BinaryTree<int> t2;
        t2.add_root(0);
        for (int i = 0; i < 10; ++i) {
            t2.add_left(i, i + 1);
        }
//post
        for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
                    CHECK_EQ(*it, i--);
        }

//pre
        i = 0;
        for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }
//in
        i = 10;
        for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
                    CHECK_EQ(*it, i--);
        }
    }

            SUBCASE("pre") {
BinaryTree<int> t1;

    }

            SUBCASE("post") {


    }

            SUBCASE("in") {


    }
}


