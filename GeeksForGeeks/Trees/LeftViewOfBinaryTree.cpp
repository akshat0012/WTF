/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
//Function to return a list containing elements of left view of the binary tree.
void helper(Node* root, vector<int>& ans) {
    // Level order traversal 
    if (root == NULL) return {};
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            Node* currNode = q.front();
            q.pop();
            // insert the left and right
            if (currNode->left) q.push(currNode->left);
            if (currNode->right) q.push(currNode->right);
            if (i == 0) ans.push_back(currNode->data);
        }
    }
    return ans; 
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> result;
    helper(root, result);
    return result;
}
