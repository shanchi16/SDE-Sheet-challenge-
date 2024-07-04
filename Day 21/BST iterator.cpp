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
class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        root = root;
        TreeNode* head = root;
        while(head){
            s.push(head);
            head = head->left;
        }
    }
    
    int next() {
        if(s.size() > 0){
            TreeNode* head = s.top();
            int ans = head->val;
            s.pop();
            head = head->right;
            while(head){
                s.push(head);
                head = head->left;  
            }

            return ans;
        }
        else {
            return -1;
        }
    }
    
    bool hasNext() {
        if(s.size() > 0) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */