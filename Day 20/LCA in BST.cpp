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
        if(root == p || root == q || !root) return root;
        int rVal = root->val, pVal = p->val, qVal = q->val;
        if(pVal > rVal && qVal > rVal) return lowestCommonAncestor(root->right, p, q);
        if(pVal < rVal && qVal < rVal) return lowestCommonAncestor(root->left, p, q);
    
        return root;
    }
};