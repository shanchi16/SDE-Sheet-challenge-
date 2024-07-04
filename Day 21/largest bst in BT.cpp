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
class Node{
    public:
    int maxi, mini, n;
    bool isBST;
    Node(int max, int min, int n, bool isBSt){
        maxi = max;
        mini = min;
        this->n = n;
        isBST = true;
    }
};
class Solution {
public:
    Node largestBST(TreeNode* root, int& ans){
        if(!root ) return Node(INT_MIN, INT_MAX, 0, true);

        Node left = largestBST(root->left, ans);
        Node right = largestBST(root->right, ans);

        if(left.maxi < root->val && right.mini > root->val && left.isBST && right.isBST){
            ans = max(ans, right.n + left.n +root->val);
            return Node(max(root->val, right.maxi), min(root->val, left.mini), right.n+left.n+root->val, true);
        } 
        ans = max({ans, left.n, right.n});
        return Node(INT_MAX, INT_MIN,  max(left.n, right.n), false);
    }

    int maxSumBST(TreeNode* root) { 
        int ans = 0;
        largestBST(root, ans);
        return ans;
    }
};