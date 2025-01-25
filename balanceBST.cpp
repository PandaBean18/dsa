#include <iostream>
#include <vector>

using namespace std;

// problem: given a bst, balance it such that the balance factor of any node is not more than |1|
// solution: convert the tree to an array using in order traversal. this will give a sorted list. Now create a binary tree from this
// by using middle of the array as node. this will ensure a balanced binary tree. Time complexity: O(n), space complexity = O(n) 

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

void inOrderTraversal(TreeNode* root, vector<TreeNode*>& path) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left, path);
    path.push_back(root);
    inOrderTraversal(root->right, path);
    
    return;
}

TreeNode* createTreeFromArray(vector<TreeNode*> arr, int start, int end) {
    if ((end-start) == 0) {
        arr[end]->right = arr[end]->left = nullptr;
        return arr[start];
    } else if ((end-start) == 1) {
        arr[start]->right = arr[end];
        arr[start]->left = nullptr;
        arr[end]->right = arr[end]->left = nullptr;
        return arr[start];
    }

    int mid = (start+end) / 2;
    TreeNode* root = arr[mid];

    root->left = createTreeFromArray(arr, start, mid-1);
    root->right = createTreeFromArray(arr, mid+1, end);
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> path;
    inOrderTraversal(root, path);

    TreeNode* newRoot = createTreeFromArray(path, 0, path.size()-1);

    return newRoot;
}
