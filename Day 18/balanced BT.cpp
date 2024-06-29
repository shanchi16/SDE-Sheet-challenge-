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
    int solve(TreeNode* root, bool& ans){
        if(root == NULL) return true;
        auto l = solve(root->left, ans);
        auto r = solve(root->right, ans);
        if(abs(r-l) > 1) ans = false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool ans = true;
        int h = solve(root, ans);

        return ans;
    }
};