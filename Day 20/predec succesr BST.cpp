/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void solve(Node* root, Node* pre, Node* suc, int key){
        
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* p = NULL;
        Node* s = NULL;
        Node* curr = root;
        while(curr){
            if(curr->key < key ){
                p = curr;
                curr = curr->right;
            } 
            else curr = curr->left;
        }
        
        curr = root;
        while(curr){
            if(curr->key > key){
                s = curr;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        
        pre = p, suc = s;
        
    }
};