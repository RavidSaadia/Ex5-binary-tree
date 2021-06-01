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

    /*******************************************
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
        t1.add_root(0);                      //*******************************************
                CHECK_NOTHROW(t1.add_left(0, 1));  //*                                          *
                CHECK_NOTHROW(t1.add_left(1, 2));  //*                  0                       *
                CHECK_NOTHROW(t1.add_right(1, 3)); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(0, 4)); //*             1       4                    *
                CHECK_NOTHROW(t1.add_right(4, 8)); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(8, 9)); //*           2   3   5    8                 *
                CHECK_NOTHROW(t1.add_left(4, 5));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, 6));  //*                 6   7    9               *
                CHECK_NOTHROW(t1.add_right(5, 7)); //********************************************

        int i = 0;
        for (auto it = t1.begin_preorder(); it != t1.end_preorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }
    }

            SUBCASE("post") {
        BinaryTree<int> t1;
        t1.add_root(9);                      //*******************************************
                CHECK_NOTHROW(t1.add_left(9, 2));  //*                                          *
                CHECK_NOTHROW(t1.add_left(2, 0));  //*                  9                       *
                CHECK_NOTHROW(t1.add_right(2, 1)); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(9, 8)); //*             2       8                    *
                CHECK_NOTHROW(t1.add_right(8, 7)); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(7, 6)); //*           0   1   5    7                 *
                CHECK_NOTHROW(t1.add_left(8, 5));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, 3));  //*                 3   4    6               *
                CHECK_NOTHROW(t1.add_right(5, 4)); //********************************************

        int i = 0;
        for (auto it = t1.begin_postorder(); it != t1.end_postorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }

    }

            SUBCASE("in") {
        BinaryTree<int> t1;
        t1.add_root(3);                      //*******************************************
                CHECK_NOTHROW(t1.add_left(3, 1));  //*                                          *
                CHECK_NOTHROW(t1.add_left(1, 0));  //*                  3                       *
                CHECK_NOTHROW(t1.add_right(1, 2)); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(3, 7)); //*             1       7                    *
                CHECK_NOTHROW(t1.add_right(7, 8)); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(8, 9)); //*           0   2   5    8                 *
                CHECK_NOTHROW(t1.add_left(7, 5));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, 4));  //*                 4   6    9               *
                CHECK_NOTHROW(t1.add_right(5, 6)); //********************************************

        int i = 0;
        for (auto it = t1.begin_inorder(); it != t1.end_inorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }

    }
}
class Car {
    int model;
public:
    Car(int model) : model(model) {}

    int get_model() const { return model; }

    bool operator==(Car &other) { return model == other.model; }

    friend ostream &operator<<(ostream &os, Car car) {
        return os<<car.model;
    }
};

TEST_CASE ("object in tree") {


    BinaryTree<Car> tree_of_cars;
            CHECK_NOTHROW(tree_of_cars.add_root(Car{1}));
            CHECK_NOTHROW(tree_of_cars.add_left(Car{1}, Car{9}));
            CHECK_NOTHROW(tree_of_cars.add_left(Car{9}, Car{4}));
            CHECK_NOTHROW(tree_of_cars.add_right(Car{9}, Car{5}));
            CHECK_NOTHROW(tree_of_cars.add_right(Car{1}, Car{3}));
            CHECK_NOTHROW(tree_of_cars.add_left(Car{1}, Car{2}));
            CHECK_NOTHROW(tree_of_cars.add_left(Car{3}, Car{8}));
            CHECK_NOTHROW(tree_of_cars.add_right(Car{3}, Car{7}));

    /*******************************************
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
        cout << tree_of_cars << endl;
    }


}

TEST_CASE ("car`s tree") {
            SUBCASE ("add root") {
        BinaryTree<Car> cars_tree;
        for (int i = 0; i < 10; ++i) {
            int root = rand();
                    CHECK_NOTHROW(cars_tree.add_root(root));
                    CHECK_EQ(*cars_tree.begin_inorder(), root);
                    CHECK_EQ(*cars_tree.begin_postorder(), root);
                    CHECK_EQ(*cars_tree.begin_preorder(), root);

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
        t1.add_root(0);                      //*******************************************
                CHECK_NOTHROW(t1.add_left(0, 1));  //*                                          *
                CHECK_NOTHROW(t1.add_left(1, 2));  //*                  0                       *
                CHECK_NOTHROW(t1.add_right(1, 3)); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(0, 4)); //*             1       4                    *
                CHECK_NOTHROW(t1.add_right(4, 8)); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(8, 9)); //*           2   3   5    8                 *
                CHECK_NOTHROW(t1.add_left(4, 5));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, 6));  //*                 6   7    9               *
                CHECK_NOTHROW(t1.add_right(5, 7)); //********************************************

        int i = 0;
        for (auto it = t1.begin_preorder(); it != t1.end_preorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }
    }

            SUBCASE("post") {
        BinaryTree<int> t1;
        t1.add_root(9);                      //*******************************************
                CHECK_NOTHROW(t1.add_left(9, 2));  //*                                          *
                CHECK_NOTHROW(t1.add_left(2, 0));  //*                  9                       *
                CHECK_NOTHROW(t1.add_right(2, 1)); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(9, 8)); //*             2       8                    *
                CHECK_NOTHROW(t1.add_right(8, 7)); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(7, 6)); //*           0   1   5    7                 *
                CHECK_NOTHROW(t1.add_left(8, 5));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, 3));  //*                 3   4    6               *
                CHECK_NOTHROW(t1.add_right(5, 4)); //********************************************

        int i = 0;
        for (auto it = t1.begin_postorder(); it != t1.end_postorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }

    }

            SUBCASE("in") {
        BinaryTree<int> t1;
        t1.add_root(3);                      //*******************************************
                CHECK_NOTHROW(t1.add_left(3, 1));  //*                                          *
                CHECK_NOTHROW(t1.add_left(1, 0));  //*                  3                       *
                CHECK_NOTHROW(t1.add_right(1, 2)); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(3, 7)); //*             1       7                    *
                CHECK_NOTHROW(t1.add_right(7, 8)); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(8, 9)); //*           0   2   5    8                 *
                CHECK_NOTHROW(t1.add_left(7, 5));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, 4));  //*                 4   6    9               *
                CHECK_NOTHROW(t1.add_right(5, 6)); //********************************************

        int i = 0;
        for (auto it = t1.begin_inorder(); it != t1.end_inorder(); ++it) {
                    CHECK_EQ(*it, i++);
        }

    }


}


