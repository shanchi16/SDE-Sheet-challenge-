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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if p or q is the root the it is LCA itself 
        if(!root || root==p || root==q ) return root;

        // find it p or q in the left part
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // find p or q in the right part of the subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if p and q is not in left part then they are in right part
        if(left==NULL) return right;
        // if p and q is not in right part then they are in left part
        if(right == NULL) return left;

        // if one is in left and other is in right then the lCA is the root itself
        return root;
    }
};

 