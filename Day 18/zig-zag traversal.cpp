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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        queue<TreeNode* > q;
        q.push(root); bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> output;
            for(int i=0; i<n; i++){
                auto front=q.front();
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                if(flag) output.push_back(front->val);
                else output.insert(output.begin(), front->val);
                
            }
            flag = !flag;
            ans.push_back(output);
        }

        return ans;
    }
};