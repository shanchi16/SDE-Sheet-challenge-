// Preorder inorder postorder in a single traversal
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
#include<stack>
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> preorder;
    vector<int> inorder;
    vector<int>  postorder;
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    stack<pair<TreeNode* ,int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto top=st.top();
        TreeNode* topp=top.first;
        st.pop();
        int num=top.second;
        if(num == 1){
            preorder.push_back(topp->data);
            st.push({topp, num+1});
            if(topp->left) st.push({topp->left, 1});
        }else if(num==2){
            inorder.push_back(topp->data);
            st.push({topp, num+1});
            if(topp->right) st.push({topp->right,1});
        }else{
            postorder.push_back(topp->data);
        }
    }
    
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
   
    return ans;
}