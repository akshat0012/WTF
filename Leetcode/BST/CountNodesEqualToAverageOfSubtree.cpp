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
class Solution {
public:
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) { 
        if (root != NULL) {
            pair<int, int> left;
            pair<int, int> right;
            if (root->left) left = dfs(root->left);
            if (root->right) right = dfs(root->right);
            int sum = left.first + right.first + root->val;
            int node = left.second + right.second + 1;
            if (sum / node == root->val) ans ++;
            return {sum, node};
        }
        return {0, 0};
    }
    int averageOfSubtree(TreeNode* root) {
        if (root->left == NULL && root->right == NULL && root->val <= 1) return 1;
        dfs(root);
        return ans;
    }
};
