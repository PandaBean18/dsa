#include <iostream>
#include <vector>

using namespace std;

// Problem: given an n*n matrix of 0 and 1s, construct a quad tree out of it

// solution: divide the matrix in size (n) by 2. 
// first quad -> 0...n/2, 0...n/2
// second quad -> 0...n/2, n/2..n
// so on
// we can solve this recursively with the base case either being a matrix of 2*2 or 1*1.

struct Node {
    bool val;
    bool isLeaf;
    Node *topLeft = NULL, *topRight = NULL, *bottomLeft = NULL, *bottomRight = NULL;
};

Node* construct(vector<vector<int>>& grid) {
    Node* node = new Node;

    if (grid.size() == 1) {
        node->isLeaf = 1;
        node->val = grid[0][0];
        return node;
    } else {
        int c = 0;
        int p = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                c |= p ^ grid[i][j];
                if (c) {
                    break;
                }
                p = grid[i][j];
            }
        }

        if (!c) {
            node->isLeaf = 1;
            node->val = p;
            return node;
        }
        node->isLeaf = 0;
        node->val = 0;

        int mid = grid.size() / 2;

        vector<vector<int>> topLeft, topRight;
        int splitFurther = 0;
        int prev = grid[0][0];

        for(int i = 0; i < mid; i++) {
            vector<int> k;
            for(int j = 0; j < mid; j++) {
                splitFurther |= prev ^ grid[i][j];
                prev = grid[i][j];
                k.push_back(prev);
            }
            topLeft.push_back(k);
        }

        if (splitFurther) {
            node->topLeft = construct(topLeft);
        } else {
            Node* t = new Node;
            t->isLeaf = 1;
            t->val = prev;
            node->topLeft = t;
        }

        splitFurther = 0;
        prev = grid[0][mid];

        for(int i = 0; i < mid; i++) {
            vector<int> k;
            for(int j = mid; j < grid.size(); j++) {
                splitFurther |= prev ^ grid[i][j];
                prev = grid[i][j];
                k.push_back(prev);
            }
            topRight.push_back(k);
        }

        if (splitFurther) {
            node->topRight = construct(topRight);
        } else {
            Node* t = new Node;
            t->isLeaf = 1;
            t->val = prev;
            node->topRight = t;
        }

        vector<vector<int>> bottomLeft, bottomRight;
        splitFurther = 0;
        prev = grid[mid][0];

        for(int i = mid; i < grid.size(); i++) {
            vector<int> k;
            for(int j = 0; j < mid; j++) {
                splitFurther |= prev ^ grid[i][j];
                prev = grid[i][j];
                k.push_back(prev);
            }
            bottomLeft.push_back(k);
        }

        if (splitFurther) {
            node->bottomLeft = construct(bottomLeft);
        } else {
            Node* t = new Node;
            t->isLeaf = 1;
            t->val = prev;
            node->bottomLeft = t;
        }

        splitFurther = 0;
        prev = grid[mid][mid];

        for(int i = mid; i < grid.size(); i++) {
            vector<int> k;
            for(int j = mid; j < grid.size(); j++) {
                splitFurther |= prev ^ grid[i][j];
                prev = grid[i][j];
                k.push_back(prev);
            }
            bottomRight.push_back(k);
        }

        if (splitFurther) {
            node->bottomRight = construct(bottomRight);
        } else {
            Node* t = new Node;
            t->isLeaf = 1;
            t->val = prev;
            node->bottomRight = t;
        }
        return node;
    }
}