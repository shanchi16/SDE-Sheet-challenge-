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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>  > mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            TreeNode* nod = t.first;
            int x = t.second.first, y = t.second.second;
            mp[x][y].insert( nod->val);

            if(nod->left) q.push({nod->left, {x-1, y+1}});
            if(nod->right) q.push({nod->right,{x+1,y+1}});
        }

        for( auto it:mp){
            vector<int> temp;
            for(auto ip:it.second){
                for(auto ipp:ip.second)
                temp.push_back(ipp);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};