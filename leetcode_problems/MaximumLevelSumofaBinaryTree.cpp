#include <iostream>
#include <climits>
#include <queue>
using namespace std;
/*
 * Maximum Level Sum of Binary Tree
 * Daily leetcode challenge
 * 15 June 23
 * Time Complexity O(N)
 */

/*
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
public:
    int maxLevelSum(TreeNode* root) {

        // basic Level Order Traversal

        queue<TreeNode*> q;
        q.push(root);
        int maxLevel = 1;
        int level = 1;
        int maxSum = root->val;
        while (!q.empty()) {
            unsigned int size = q.size();
            int currSum = INT_MIN;
            for (int i = 0; i < size; i ++)
            {
                TreeNode *currNode = q.front(); // the very first element in our queue is currNode for every iteration
                q.pop(); // pop the current element

                currSum += currNode->val;

                if (currNode->left != nullptr) { // if there is some value in left node
                    q.push(currNode->left);
                }
                if (currNode->right != nullptr) { // is there is some value in right node
                    q.push(currNode->right);
                }
            }
            // we'll increment the level everytime we get sum greater than the previous one
            if (currSum > maxSum) {
                maxSum = currSum;
                maxLevel = level;
            }
            level ++;
        }
        return maxLevel;
    }
};
