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
    void helper(TreeNode* root, unordered_map<int, int>& mp) {
        if (root != NULL) {
            mp[root->val]++;
            if (root->left) helper(root->left, mp);
            if (root->right) helper(root->right, mp);
        } else return ;
    }
    vector<int> findMode(TreeNode* root) {
        int maxFrequency = INT_MIN;
        unordered_map<int, int> mp;
        vector<int> ans;
        helper(root, mp);
        for (auto& el:mp) maxFrequency = max(maxFrequency, el.second);
        for (auto& el:mp) {
            if (el.second >= maxFrequency) ans.push_back(el.first);
        }
        return ans;
    }
}; 
