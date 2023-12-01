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
private:
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // basic Level Order Traversal

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> outerVector;
        while (!q.empty()) {
            vector<int> innerVector;
            int size = q.size();

            for (int i = 0; i < size; i ++) {

                TreeNode *currNode = q.front();
                q.pop();

                if (currNode == nullptr) return;

                if (currNode == NULL) return outerVector;

                if (currNode->left != NULL) {
                    q.push(currNode->left);
                }
                if (currNode->right != NULL) {
                    q.push(currNode->right);
                }

                innerVector.push_back(currNode->val);
            }
            outerVector.insert(outerVector.begin(), innerVector);
        }

        return outerVector;
    }
};
