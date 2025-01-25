#include <iostream>
#include <vector>

using namespace std;

// problem: given a sorted array, convert it into a balanced binarySearchTree.

// solution 1: create a recursive function to do it

struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL;
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* node = new TreeNode;

    if (nums.size() == 1) {
        node->val = nums[0];
        return node;
    } else if (nums.size() == 2) {
        node->val = nums[0];

        node->right = new TreeNode;
        node->right->val = nums[1];

        return node;
    }

    int mid = nums.size() / 2;
    node->val = nums[mid];

    vector<int> left;
    vector<int> right;
    copy(nums.begin(), nums.begin()+(mid-1), back_inserter(left));
    copy(nums.begin()+(mid+1), nums.end(), back_inserter(right));

    node->left = sortedArrayToBST(left);
    node->right = sortedArrayToBST(right);

    return node;
}