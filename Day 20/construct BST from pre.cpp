// Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* solve(int prest, int prend, int inst, int inend, vector<int> & pre, map<int, int> & mp){
        if(prest > prend || inst > inend) return NULL;
        TreeNode* root = new TreeNode(pre[prest]);

        int inNow = mp[pre[prest]];
        int cnt = inNow-inst;

        root->left = solve(prest+1, prest+cnt, inst, inNow-1, pre, mp);
        root->right = solve(prest+cnt+1, prend, inNow+1, inend, pre, mp);

        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        inorder = preorder;
        sort(inorder.begin(), inorder.end());

        map<int, int> mp;
        for(int i=0; i<preorder.size(); i++) mp[inorder[i]] = i;
        
        int n = preorder.size();
        return solve(0, n-1, 0, n-1, preorder, mp);

    }
};