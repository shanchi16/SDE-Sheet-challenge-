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
TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        
        // solution 1
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev -> right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                // LL bna rhe h to nodes k left ko NULL bhi krna h
                curr->left = NULL;
            }
            else{
            curr = curr->right;
            }
        }


        // solution 2
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        prev = root; 
        root->left = NULL;
    }
};