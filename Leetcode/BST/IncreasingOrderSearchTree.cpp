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

// o(n)
class Solution {
public:
    vector<TreeNode*> inorder;
    TreeNode* head = new TreeNode(-1);
    TreeNode* currNode = head;

    void dfs(TreeNode* root) {
        if (root != NULL) {
            if (root->left) dfs(root->left);
            inorder.push_back(root);
            if (root->right) dfs(root->right);
        }
    }
    void createTree() {
        for (TreeNode* Node:inorder) {
            currNode->right = Node;
            Node->left = NULL;
            currNode = currNode->right;
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        createTree();
        return head->right;
    }
};


// O(1) 
class Solution {
public:
    TreeNode* head = new TreeNode(-1);
    TreeNode* currNode = head;
    void dfs(TreeNode* root) {
        if (root != NULL) {
            if (root->left) dfs(root->left);
            currNode->right = root;
            root->left = NULL;
            currNode = currNode->right;
            if (root->right) dfs(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        return head->right;
    }
};
