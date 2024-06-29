
//  Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void preorderTraversal(TreeNode* root,  vector<int>& preorder) {
        if(root == NULL) return;
        preorder.push_back(root -> val);
        preorderTraversal(root->left, preorder);
        preorderTraversal(root->right, preorder);
    }
    void postOrderTraversal(TreeNode* root,vector<int>& postorder) {
        if(root == NULL) return;
        postOrderTraversal(root-> left, postorder);
        postOrderTraversal(root->right, postorder);
        postorder.push_back(root->val);
    }
    void inorderTraversal(TreeNode* root,vector<int>& inorder) {
        if(root == NULL) return;
        inorderTraversal(root-> left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);

    }

    vector<int> solve(TreeNode* root){
        vector<int> inorder;
        vector<int> preorder;
        vector<int> postorder;
        preorderTraversal(root, preorder);
        postOrderTraversal(root, postorder);
        inorderTraversal(root, inorder);

    }
};