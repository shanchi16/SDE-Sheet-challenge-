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
    void solve(TreeNode* root, int& cnt, int& ans){
        if(root == NULL) return ;
        cout<< "enter ";
        solve(root->left, cnt, ans);
        cnt--;
        cout<< cnt<< " ";
        if(cnt == 0) {
            ans = root->val;
            return ;
        }

        solve(root->right, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        int ans, cnt = k;

        solve(root, cnt, ans);
        return ans;
    }
};