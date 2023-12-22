class Solution {
  public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int line = frontNode.second;
            Node* node = frontNode.first;
            mp[line] = node->data;
            if (node->left) q.push({node->left, line-1});
            if (node->right) q.push({node->right, line+1});
        }
        for (auto it:mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
