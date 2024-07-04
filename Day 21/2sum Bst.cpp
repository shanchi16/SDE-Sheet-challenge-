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
    stack<TreeNode* > left;
    stack<TreeNode*> right;

    void push_left(TreeNode* root){
        // next element in BST in inorder i.e. BST iterator problem
        TreeNode* temp = root;
        while(temp){
            left.push(temp);
            temp = temp->left;
        }
    }
    void push_right(TreeNode* root){
        // previous element in BST in inorder i.e. BST iterator
        TreeNode* temp = root;
        while(temp){
            right.push(temp);
            temp = temp->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        push_left(root);
        push_right(root);

        while(!left.empty() || !right.empty()){
            TreeNode* l = left.top();
            TreeNode* r = right.top();
            int sum = l->val + r->val;
            if(l == r) return false;
            if(sum == k) return true;
            else if(sum < k) {
                TreeNode* t = left.top();
                left.pop();
                push_left(t->right);
            }
            else{
                TreeNode* t = right.top();
                right.pop();
                push_right(t->left);
            }
        }
        return false;
    }
};