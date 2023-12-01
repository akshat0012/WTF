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
    TreeNode* helper(vector<int>& vec, int& i, int bound) {
        if (i == vec.size() || vec[i] > bound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(vec[i]);
        i++;
        root->left = helper(vec, i, root->val);
        root->right = helper(vec, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;return helper(preorder, i, INT_MAX);
    }
};
