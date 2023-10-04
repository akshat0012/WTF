/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    Solution () {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    // level order traversal to mark the parents of childs
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* currNode = queue.front();
            queue.pop();
            if (currNode->left) {
                map[currNode->left] = currNode; // left(child) -> currNode (parent)
                queue.push(currNode->left);        
            }
            if (currNode->right) {
                map[currNode->right] = currNode;
                queue.push(currNode->right);
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        unordered_map<TreeNode*, TreeNode*> map;
        markParents(root, map);
        
        unordered_map<TreeNode*, bool) visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int distanceCovered = 0; 

        while (!queue.empty()) {
            if (distanceCovered == k) {
                break;
            }
            int sizeOfQueue = queue.size();
            for (int i=0; i<sizeOfQueue; i++) {
                if (currNode->left && !visited[current->left]) {
                    queue.push(currNode->left);
                    visited[currNode->left] = true;
                }
                if (currNode->right && !visited[currNode->right]) {
                    queue.push(currNode->right);
                    visited[currNode->right] = true;
                }
                if (map[currNode] && !visited[map[currNode]]) {
                    queue.push(map[currNode]);
                    visited[map[currNode] = true;
                }
            }
            
            while (!queue.empty()) {
                TreeNode* currentNode = queue.front();
                result.push_back(currentNode->val);
                queue.pop();
            }
        }
    }
};
