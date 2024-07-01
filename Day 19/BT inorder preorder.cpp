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
    TreeNode* solve(int pst, int pend, int ist, int iend, unordered_map<int,int>& mp, vector<int>& pre){
        if(ist<0 || pst > pend || ist > iend || iend >= mp.size() || pst<0 || pend >= pre.size()) return NULL;

        int value = pre[pst];   
        TreeNode* temp = new TreeNode(value);
        int idx = mp[value];
        int num = idx-ist;

        temp->left = solve(pst+1, pst+num, ist, idx-1,mp, pre);
        temp->right = solve(pst+num+1, pend, idx+1, iend, mp, pre);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = preorder.size(), q = inorder.size();
        int pst=0, pend=p-1, ist=0, iend = q-1;
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return solve(pst, pend, ist, iend, mp, preorder);


    }
};