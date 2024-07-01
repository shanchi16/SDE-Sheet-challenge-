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
    int solve(TreeNode* root, int& ans){
        if(root == NULL) return 0;

        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        int v = root->val;
        ans = max({l+v, r+v, ans, v, l+r+v});
        cout<<ans<< " ";
        return max({v,l+v,r+v}) ;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int tmemp = solve(root, ans);

        return ans;
    }
};