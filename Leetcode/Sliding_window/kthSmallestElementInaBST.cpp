#include <bits/stdc++.h>
using namespace std;
/*
 * Kth Smallest Element In BST
 * O(n)
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
private:
    int ans = 0;
public:
    void inorder(TreeNode* node, int& k) {

        if (node == NULL) return;
        inorder(node->left, k);
        if (--k == 0) ans = node->val;
        inorder(node->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {

        inorder(root, k);
        return ans;
    }
};









