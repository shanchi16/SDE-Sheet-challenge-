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

void solve(vector<int>& ans, int cnt, Node* root){
    if(root == NULL) return;
    
    if(ans.size() == cnt) ans.push_back(root->data);
    if(root->left) solve(ans, cnt+1, root->left);
    if(root->right) solve(ans, cnt+1, root->right);
    
}
vector<int> leftView(Node *root)
{
    vector<int>  ans;
    solve(ans, 0, root);
    
    return ans;
   
}