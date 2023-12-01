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
    void helper(TreeNode* root, vector<int>& ans) {
        // Level order traversal
        if (root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
                if (i == size-1) ans.push_back(currNode->val);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};
