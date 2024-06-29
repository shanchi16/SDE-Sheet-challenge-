class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mp; // to store the horizontal index and the node 
        queue<pair<Node*, int> > q; // vertical level ans the node
        vector<int> ans;
        
        if(root == NULL) return ans;
        q.push({root, 0});
        mp[0] = root->data;
        while(!q.empty()){
            Node* top = q.front().first;
            int y = q.front().second;
            q.pop();
            
            mp[y] = top->data;
            if(top->left) q.push({top->left, y-1});
            if(top->right) q.push({top->right, y+1});
            
        }
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};