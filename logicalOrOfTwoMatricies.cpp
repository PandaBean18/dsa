#include <iostream>

using namespace std;

// problem: given two quad trees representing two matricies A and B of size n*n, generate a quad tree for a matrix C such that
// C = A | B

// solution: since the trees represent the matrix of same order, that means that grids at the same level will have same number
// of elements. Also, lets say either Node A or B or both leaves on the same level. This means that they have the same number of
// elements they both have will be same. Also either A or B (or both) are leaves, meaning in one of them, all the elements are either
// all 0 or all 1s
// if the node is all 1s, then, we can confidently say that the intersection of A and B (A|B) will have all 1's. This is because 
// 1 | 0 == 1 | 1 == 1 so the data of the other node does not matter, we can just return the leaf node

// if the leaf node is all 0's, then A|B will have the content of the non-leaf node. this is because 0|c = c where c is 0 or 1

// we can use these two conditions to form a base case for a recursive function.
// if either of the above two conditions are not true, we can create a new node that is not leaf, and the find values for all four of
// its children recursively

// there is a possibility that after finding children, all children are leaves with the same value, if this is the case, then
// the root needs to be updated such: isleaf = true; val = val of children; children = null

struct Node {
    int val;
    bool isLeaf;
    Node *topLeft = NULL, *topRight = NULL, *bottomLeft = NULL, *bottomRight = NULL;
};

Node* intersect(Node* a, Node* b) {
    Node* c;
    if (a->isLeaf) {
        if (a->val == 1) {
            c = a;
        } else {
            c = b;
        }
        return c;
    } else if (b->isLeaf) {
        if (b->val == 1) {
            c = b;
        } else {
            c = a;
        }
        return c;
    }
    c = new Node;
    c->isLeaf = 0;
    c->val = 0;

    c->topLeft = intersect(a->topLeft, b->topLeft);
    c->topRight = intersect(a->topRight, b->topRight);
    c->bottomLeft = intersect(a->bottomLeft, b->bottomLeft);
    c->bottomRight = intersect(a->bottomRight, b->bottomRight);

    if (c->topLeft->isLeaf && c->topRight->isLeaf && c->bottomLeft && c->bottomRight) {
        if (c->topLeft->val && c->topRight->val && c->bottomLeft->val && c->bottomRight->val) {
            c->isLeaf = 1;
            c->val = 1;
            c->topLeft = NULL;
            c->topRight = NULL;
            c->bottomLeft = NULL;
            c->bottomRight = NULL;
        } else if (!c->topLeft->val && !c->topRight->val && !c->bottomLeft->val && !c->bottomRight->val) {
            c->isLeaf = 1;
            c->val = 0;
            c->isLeaf = 1;
            c->val = 1;
            c->topLeft = NULL;
            c->topRight = NULL;
            c->bottomLeft = NULL;
            c->bottomRight = NULL;
        }
    }
    return c;
}