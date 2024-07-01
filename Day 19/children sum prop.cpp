struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    
         bool ans=1;
    int func(Node*root){
        
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        int left=func(root->left);
        int right=func(root->right);
        if(root->data!=left+right){
            ans=0;
        }
        
    }
    int isSumProperty(Node *root)
    {
      int x=func(root);
      
      return ans;
    }
    
};