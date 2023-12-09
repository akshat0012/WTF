class Solution {
public:
    void forLeft(Node* root, vector<int>& ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;

        ans.push_back(root->data);

        if (root->left)
            forLeft(root->left, ans);
        else
            forLeft(root->right, ans);
    }

    void forLeaf(Node* root, vector<int>& ans) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
            return;
        }

        forLeaf(root->left, ans);
        forLeaf(root->right, ans);
    }

    void forRight(Node* root, vector<int>& ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;

        if (root->right)
            forRight(root->right, ans);
        else
            forRight(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        ans.push_back(root->data);

        forLeft(root->left, ans);
        forLeaf(root->left, ans);
        forLeaf(root->right, ans);
        forRight(root->right, ans);

        return ans;
    }
};
