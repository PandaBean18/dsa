#include <iostream>
#include <vector>

using namespace std;

// Problem: given the post order and pre order traversal of a a binary tree, construct the binary tree.
// Solution: Some observations : 
//          1. The first element of pre order and the last element of the post order are the root
//          2. In preorder, the element to the immediate right of the root is the root of the left sub tree
//          3. In postorder, the element to the immediate left of the root (-2 index) is the root of the right subtree
//      lets call the root of left subtree x and root of right subtree y
//          4. the subarray of preorder OR postorder from index(x)...index(y), latter exclusive, gives the preorder OR postorder of left
//             or right tree.

struct TreeNode {
    int val;
    TreeNode *left = nullptr, *right = nullptr;
};

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    TreeNode* root = new TreeNode;
    if (pre.size() == 1) {
        root->val = pre[0];
        root->right = root->left = nullptr;
        return root;
    } else if (pre.size() == 0) {
        return nullptr;
    } else if (pre[pre.size()-1] == post[0]) {
        root->val = pre[0];
        TreeNode* last = root;
        TreeNode* t;

        for(int i = 1; i < pre.size(); i++) {
            t = new TreeNode();
            t->val = pre[i];
            last->left = t;
            last = last->left;
        }

        return root;
    }

    vector<int> preLeft;
    vector<int> preRight;
    vector<int> postLeft;
    vector<int> postRight;

    root->val = pre[0];

    int l = pre[1];
    int r = post[post.size()-2];
    if (l != r) {
        int passed = 0;
        for(int i = 1; i < pre.size(); i++) {
            if (pre[i] == r) {
                passed = 1;
                preRight.push_back(pre[i]);
                continue;
            } else if(!passed) {
                preLeft.push_back(pre[i]);
            } else {
                preRight.push_back(pre[i]);
            }
        }

        passed = 0;
        for(int i = 0; i < post.size()-1; i++) {
            if (post[i] == l) {
                passed = 1;
                postLeft.push_back(post[i]);
                continue;
            } else if(!passed) {
                postLeft.push_back(post[i]);
            } else {
                postRight.push_back(post[i]);
            }
        }

        root->left = constructFromPrePost(preLeft, postLeft);
        root->right = constructFromPrePost(preRight, postRight);
    } else {
        for(int i = 1; i < pre.size(); i++) {
            preLeft.push_back(pre[i]);
        }

        for(int i = 0; i < post.size()-1; i++) {
            postLeft.push_back(post[i]);
        }

        root->left = constructFromPrePost(preLeft, postLeft);
        root->right = nullptr;
    }
    return root;
}