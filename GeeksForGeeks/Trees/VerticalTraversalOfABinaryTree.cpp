class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, vector<int>> mp;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            
            // Get the level and the node
            Node* node = frontNode.first;
            int line = frontNode.second;
            
            // push the elements in mp
            mp[line].push_back(node->data);
               
            if (node->left) q.push({node->left, line-1});
            if (node->right) q.push({node->right, line+1});
        }
        for (auto firstIt:mp) {
            for (auto secondIt:firstIt.second) {
                ans.push_back(secondIt);
            }
        }
        return ans;
    }
};
