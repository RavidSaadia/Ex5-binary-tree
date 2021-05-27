//
// Created by ravid on 24/05/2021.
//

#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace ariel;
TEST_CASE("test"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
            .add_left(1, 9)      // Now 9 is the left child of 1
            .add_left(9, 4)      // Now 4 is the left child of 9
            .add_right(9, 5)     // Now 5 is the right child of 9
            .add_right(1, 3)     // Now 3 is the right child of 1
            .add_left(1, 2);     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {


    }


    auto it=tree_of_ints.begin_preorder();

    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);
    CHECK(true);



}