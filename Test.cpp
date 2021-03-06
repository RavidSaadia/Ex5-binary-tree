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

#include "sources/BinaryTree.hpp"

using namespace ariel;
TEST_CASE ("int tree") {

            SUBCASE ("Test Basic Tree ") {

        BinaryTree<int> tree_of_ints;
                CHECK_NOTHROW(tree_of_ints.add_root(1));
                CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
                CHECK_NOTHROW(tree_of_ints.add_left(9, 4));
                CHECK_NOTHROW(tree_of_ints.add_right(9, 5));
                CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
                CHECK_NOTHROW(tree_of_ints.add_left(1, 2));// overload node
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
                    CHECK_NOTHROW(t1.add_right(root, right));
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


TEST_CASE ("string tree") {
            SUBCASE ("Test Basic Tree ") {

        BinaryTree<string> tree_of_string;
                CHECK_NOTHROW(tree_of_string.add_root("1"));
                CHECK_NOTHROW(tree_of_string.add_left("1", "9"));
                CHECK_NOTHROW(tree_of_string.add_left("9", "4"));
                CHECK_NOTHROW(tree_of_string.add_right("9", "5"));
                CHECK_NOTHROW(tree_of_string.add_right("1", "3"));
                CHECK_NOTHROW(tree_of_string.add_left("1", "2"));// overload node
                CHECK_NOTHROW(tree_of_string.add_left("3", "8"));
                CHECK_NOTHROW(tree_of_string.add_right("3", "7"));

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
            cout << tree_of_string << endl;
        }


    }

            SUBCASE ("add root") {
        BinaryTree<string> string_tree;
        for (int i = 0; i < 10; ++i) {
            string root = to_string(rand());
                    CHECK_NOTHROW(string_tree.add_root(root));
                    CHECK_EQ(*string_tree.begin_inorder(), root);
                    CHECK_EQ(*string_tree.begin_postorder(), root);
                    CHECK_EQ(*string_tree.begin_preorder(), root);

        }
    }

            SUBCASE ("add right") {
        BinaryTree<string> t1;
        for (int i = 0; i < 10; ++i) {
            string root = to_string(rand());
            string right = to_string(rand());

                    CHECK_NOTHROW(t1.add_root(root));
                    CHECK_NOTHROW(t1.add_right(root, right));
                    CHECK_EQ(*(t1.begin_inorder()), right);
                    CHECK_EQ(*t1.begin_postorder(), right);
                    CHECK_EQ(*t1.begin_preorder(), root);

        }
        //    //   tree with only right sun`s from 0 to 10
        // root-> 0
        //         \
        //          1-2-3-4-5-6-7-8-9-10

        BinaryTree<string> t2;
        t2.add_root("0");
        for (int i = 0; i < 10; ++i) {
            t2.add_right(to_string(i), to_string(i + 1));
        }
        int i = 10; // compere int
        for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
                    CHECK_EQ(*it, to_string(i--));
        }

        //post
        i = 0;
        for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
                    CHECK_EQ(*it, to_string(i++));
        }

        //in
        i = 0;
        for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
                    CHECK_EQ(*it, to_string(i++));
        }

    }

            SUBCASE ("add left") {
        BinaryTree<string> t1;
        for (int i = 0; i < 10; ++i) {
            string root = to_string(rand());
            string right = to_string(rand());

                    CHECK_NOTHROW(t1.add_root(root));
                    CHECK_NOTHROW(t1.add_left(root, right));
                    CHECK_EQ(*(t1.begin_inorder()), right);
                    CHECK_EQ(*t1.begin_postorder(), right);
                    CHECK_EQ(*t1.begin_preorder(), root);
        }
        //    //   tree with only left sun`s from 0 to 10
        //               root-> 0
        //                     /
        // 10-9-8-7-6-5-4-3-2-1

        int i = 10; // compere int
        BinaryTree<string> t2;
        t2.add_root("0");
        for (int i = 0; i < 10; ++i) {
            t2.add_left(to_string(i), to_string(i + 1));
        }
//post
        for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
                    CHECK_EQ(*it, to_string(i--));
        }

//pre
        i = 0;
        for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
                    CHECK_EQ(*it, to_string(i++));
        }
//in
        i = 10;
        for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
                    CHECK_EQ(*it, to_string(i--));
        }
    }

            SUBCASE("pre") {
        BinaryTree<string> t1;
        t1.add_root("0");                      //*******************************************
                CHECK_NOTHROW(t1.add_left("0", "1"));  //*                                          *
                CHECK_NOTHROW(t1.add_left("1", "2"));  //*                  0                       *
                CHECK_NOTHROW(t1.add_right("1", "3")); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right("0", "4")); //*             1       4                    *
                CHECK_NOTHROW(t1.add_right("4", "8")); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right("8", "9")); //*           2   3   5    8                 *
                CHECK_NOTHROW(t1.add_left("4", "5"));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left("5", "6"));  //*                 6   7    9               *
                CHECK_NOTHROW(t1.add_right("5", "7")); //********************************************

        int i = 0;
        for (auto it = t1.begin_preorder(); it != t1.end_preorder(); ++it) {
                    CHECK_EQ(*it, to_string(i++));
        }
    }

            SUBCASE("post") {
        BinaryTree<string> t1;
        t1.add_root("9");                      //*******************************************
                CHECK_NOTHROW(t1.add_left("9", "2"));  //*                                          *
                CHECK_NOTHROW(t1.add_left("2", "0"));  //*                  9                       *
                CHECK_NOTHROW(t1.add_right("2", "1")); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right("9", "8")); //*             2       8                    *
                CHECK_NOTHROW(t1.add_right("8", "7")); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right("7", "6")); //*           0   1   5    7                 *
                CHECK_NOTHROW(t1.add_left("8", "5"));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left("5", "3"));  //*                 3   4    6               *
                CHECK_NOTHROW(t1.add_right("5", "4")); //********************************************

        int i = 0;
        for (auto it = t1.begin_postorder(); it != t1.end_postorder(); ++it) {
                    CHECK_EQ(*it, to_string(i++));
        }

    }

            SUBCASE("in") {
        BinaryTree<string> t1;
        t1.add_root("3");                      //*******************************************
                CHECK_NOTHROW(t1.add_left("3", "1"));  //*                                          *
                CHECK_NOTHROW(t1.add_left("1", "0"));  //*                  3                       *
                CHECK_NOTHROW(t1.add_right("1", "2")); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right("3", "7")); //*             1       7                    *
                CHECK_NOTHROW(t1.add_right("7", "8")); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right("8", "9")); //*           0   2   5    8                 *
                CHECK_NOTHROW(t1.add_left("7", "5"));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left("5", "4"));  //*                 4   6    9               *
                CHECK_NOTHROW(t1.add_right("5", "6")); //********************************************

        int i = 0;
        for (auto it = t1.begin_inorder(); it != t1.end_inorder(); ++it) {
                    CHECK_EQ(*it, to_string(i++));
        }

    }
}

class Car {
    int model;
public:
    Car(int model) : model(model) {}

    int get_model() const { return model; }

    bool operator==(Car &other) const { return model == other.model; }

    friend ostream &operator<<(ostream &os, const Car &car) {
        return os << car.model;
    }
};

TEST_CASE ("object in tree") {


    BinaryTree<Car> tree_of_cars;                                  //********************************************
            CHECK_NOTHROW(tree_of_cars.add_root(Car{1}));          //*                                          * └──1
            CHECK_NOTHROW(tree_of_cars.add_left(Car{1}, Car{9}));  //*                 1                        *  ├──3
            CHECK_NOTHROW(tree_of_cars.add_left(Car{9}, Car{4}));  //*               /   \                      *  │ ├──7
            CHECK_NOTHROW(tree_of_cars.add_right(Car{9}, Car{5})); //*             2       3                    *  │ └──8
            CHECK_NOTHROW(tree_of_cars.add_right(Car{1}, Car{3})); //*            / \     /  \                  *  └──2
            CHECK_NOTHROW(tree_of_cars.add_left(Car{1}, Car{2}));  //*           4   5   8    7                 *    ├──5
            CHECK_NOTHROW(tree_of_cars.add_left(Car{3}, Car{8}));  //*                                          *    └──4
            CHECK_NOTHROW(tree_of_cars.add_right(Car{3}, Car{7})); //********************************************

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
                    CHECK_EQ(cars_tree.begin_inorder()->get_model(), root);
                    CHECK_EQ(cars_tree.begin_postorder()->get_model(), root);
                    CHECK_EQ(cars_tree.begin_preorder()->get_model(), root);

        }
    }

            SUBCASE ("add right") {
        BinaryTree<Car> t1;
        for (int i = 0; i < 10; ++i) {
            int root = rand();
            int right = rand();
                    CHECK_NOTHROW(t1.add_root(Car{root}));
                    CHECK_NOTHROW(t1.add_left(root, Car{right}));
                    CHECK_EQ((t1.begin_inorder()->get_model()), right);
                    CHECK_EQ(t1.begin_postorder()->get_model(), right);
                    CHECK_EQ(t1.begin_preorder()->get_model(), root);

        }
        //    //   tree with only right sun`s from 0 to 10
        // root-> 0
        //         \
        //          1-2-3-4-5-6-7-8-9-10

        BinaryTree<Car> t2;
        t2.add_root(Car{0});
        for (int i = 0; i < 10; ++i) {
            t2.add_right(i, Car{i + 1});
        }
        int i = 10; // compere int
        for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
                    CHECK_EQ(it->get_model(), i--);
        }

        //post
        i = 0;
        for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
                    CHECK_EQ(it->get_model(), i++);
        }

        //in
        i = 0;
        for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
                    CHECK_EQ(it->get_model(), i++);
        }

    }

            SUBCASE ("add left") {
        BinaryTree<Car> t1;
        for (int i = 0; i < 10; ++i) {
            int root = rand();
            int left = rand();
                    CHECK_NOTHROW(t1.add_root(Car{root}));
                    CHECK_NOTHROW(t1.add_left(root, Car{left}));
                    CHECK_EQ((t1.begin_inorder()->get_model()), left);
                    CHECK_EQ(t1.begin_postorder()->get_model(), left);
                    CHECK_EQ(t1.begin_preorder()->get_model(), root);

        }
        //    //   tree with only left sun`s from 0 to 10
        //               root-> 0
        //                     /
        // 10-9-8-7-6-5-4-3-2-1

        int i = 10; // compere int
        BinaryTree<Car> t2;
        t2.add_root(Car{0});
        for (int i = 0; i < 10; ++i) {
            t2.add_left(i, Car{i + 1});
        }
//post
        for (auto it = t2.begin_postorder(); it != t2.end_postorder(); ++it) {
                    CHECK_EQ(it->get_model(), i--);
        }

//pre
        i = 0;
        for (auto it = t2.begin_preorder(); it != t2.end_preorder(); ++it) {
                    CHECK_EQ(it->get_model(), i++);
        }
//in
        i = 10;
        for (auto it = t2.begin_inorder(); it != t2.end_inorder(); ++it) {
                    CHECK_EQ(it->get_model(), i--);
        }
    }

            SUBCASE("pre") {
        BinaryTree<Car> t1;
        t1.add_root(Car{0});                      //*******************************************
                CHECK_NOTHROW(t1.add_left(0, Car{1}));  //*                                          *
                CHECK_NOTHROW(t1.add_left(1, Car{2}));  //*                  0                       *
                CHECK_NOTHROW(t1.add_right(1, Car{3})); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(0, Car{4})); //*             1       4                    *
                CHECK_NOTHROW(t1.add_right(4, Car{8})); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(8, Car{9})); //*           2   3   5    8                 *
                CHECK_NOTHROW(t1.add_left(4, Car{5}));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, Car{6}));  //*                 6   7    9               *
                CHECK_NOTHROW(t1.add_right(5, Car{7})); //********************************************

        int i = 0;
        for (auto it = t1.begin_preorder(); it != t1.end_preorder(); ++it) {
                    CHECK_EQ(it->get_model(), i++);
        }
    }

            SUBCASE("post") {
        BinaryTree<Car> t1;
        t1.add_root(Car{9});                      //*******************************************
                CHECK_NOTHROW(t1.add_left(9, Car{2}));  //*                                          *
                CHECK_NOTHROW(t1.add_left(2, Car{0}));  //*                  9                       *
                CHECK_NOTHROW(t1.add_right(2, Car{1})); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(9, Car{8})); //*             2       8                    *
                CHECK_NOTHROW(t1.add_right(8, Car{7})); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(7, Car{6})); //*           0   1   5    7                 *
                CHECK_NOTHROW(t1.add_left(8, Car{5}));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, Car{3}));  //*                 3   4    6               *
                CHECK_NOTHROW(t1.add_right(5, Car{4})); //********************************************

        int i = 0;
        for (auto it = t1.begin_postorder(); it != t1.end_postorder(); ++it) {
                    CHECK_EQ(it->get_model(), i++);
        }

    }

            SUBCASE("in") {
        BinaryTree<Car> t1;
        t1.add_root(Car{3});                      //*******************************************
                CHECK_NOTHROW(t1.add_left(3, Car{1}));  //*                                          *
                CHECK_NOTHROW(t1.add_left(1, Car{0}));  //*                  3                       *
                CHECK_NOTHROW(t1.add_right(1, Car{2})); //*               /    \                     *
                CHECK_NOTHROW(t1.add_right(3, Car{7})); //*             1       7                    *
                CHECK_NOTHROW(t1.add_right(7, Car{8})); //*            / \     /  \                  *
                CHECK_NOTHROW(t1.add_right(8, Car{9})); //*           0   2   5    8                 *
                CHECK_NOTHROW(t1.add_left(7, Car{5}));  //*                  / \    \                *
                CHECK_NOTHROW(t1.add_left(5, Car{4}));  //*                 4   6    9               *
                CHECK_NOTHROW(t1.add_right(5, Car{6})); //********************************************

        int i = 0;
        for (auto it = t1.begin_inorder(); it != t1.end_inorder(); ++it) {
                    CHECK_EQ(it->get_model(), i++);
        }

    }


}

TEST_CASE ("wrong action") {
            SUBCASE("add node") {
        BinaryTree<int> t1;
        CHECK_THROWS(t1.add_left(2,4));// add left before root
        CHECK_THROWS(t1.add_right(2,4));// add right before root
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
        //try to add node
                CHECK_THROWS(t1.add_left(10, 4));
                CHECK_THROWS(t1.add_left(34, 21));
                CHECK_THROWS(t1.add_left(55, 4));
                CHECK_THROWS(t1.add_left(14, 1));
                CHECK_THROWS(t1.add_left(100, 78));
    }
}


