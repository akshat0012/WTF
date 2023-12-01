#include <bits/stdc++.h>
using namespace std;

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

/*
 * First search the Node
 * Then delete the Node
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
private:
    TreeNode* helper(TreeNode* root) {
        if (root->right == NULL) {
            return root->right;
        }
        else if (root->left == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRightOfLeftChild = lastRight(root->left);
        lastRightOfLeftChild->right = rightChild;

        return root->left;
    }

    TreeNode* lastRight(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        return lastRight(root->right);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == NULL){
            return NULL;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }

        }
        return dummy;
    }
};