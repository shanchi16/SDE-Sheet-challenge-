/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,pair<int,int>> > qt;
        int ln=0, rn=0;
        vector<int> ans;
        if(root == NULL) return ans;
        ans.push_back(root->data);
        qt.push({root, {0,0}});
        while(!qt.empty()){
            
            int n=qt.size();
            for(int i=0; i<n; i++){
                auto temp = qt.front();
                qt.pop();
                Node* nod = temp.first; 
                int x=temp.second.first, y=temp.second.second;
                if(nod->left) qt.push({nod->left, {x-1, y+1}});
                if(nod->right) qt.push({nod->right, {x+1, y+1}});
                if(x<ln){
                    ans.insert(ans.begin(),nod->data);
                    ln=x;
                }
                if(x>rn){
                    ans.push_back(nod->data);
                    rn=x;
                }
            }
            
        }
        
        return ans;
    }

};
