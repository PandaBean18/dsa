#include <iostream>
#include <vector>

using namespace std;

// Problem: given an array of integers called nums with non repeating numbers, construct a maximum binary tree such that root has the
// largest value.

// solution: find the maximum element in the array, then the left child of the array is the maxBinaryTree of the left half of the array
// and right child is right half

struct TreeNode {
    int val;
    TreeNode *left = nullptr, *right = nullptr;
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode* root = new TreeNode;
    if (nums.size() == 1) {
        root->val = nums[0];
        return root;
    }

    int max = nums[0];
    int index = 0;
    for(int i = 1; i < nums.size(); i++) {
        if (nums[i] > max) {
            max = nums[i];
            index = i;
        }
    }

    root->val = max;
    vector<int> left = {};
    vector<int> right = {};

    if (index == 0) {
        copy(nums.begin()+1, nums.end(), back_inserter(right));
        root->right = constructMaximumBinaryTree(right);
        root->left = nullptr;
        return root;
    } else if (index == nums.size()-1) {
        copy(nums.begin(), nums.end()-1, back_inserter(left));
        root->right = nullptr;
        root->left = constructMaximumBinaryTree(left);
        return root;
    } else {
        copy(nums.begin(), nums.begin()+index, back_inserter(left));
        copy(nums.begin()+index+1, nums.end(), back_inserter(right));

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;
    }
}