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
class Solution {
public:
    int solve(TreeNode* root, int n){
        // if(root == NULL) return 0;
        int l=0, r=0;

        if(root->left) l=solve(root->left, n);
        if(root->right) r = solve(root->right, n);
        return max(l,r) + 1;
    }
    int maxDepth(TreeNode* root) {
        return solve(root,0);
    }
};