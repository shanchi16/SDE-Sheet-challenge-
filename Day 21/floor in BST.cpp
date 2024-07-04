void solve(TreeNode<int>* root, int& ans, int x){
    if(root == NULL) return;
    int temp = root->val;
    if(temp <= x && temp > ans) ans = temp;
    if(temp > x) solve(root->left, ans, x);
    else if(temp < x) solve(root->right, ans, x);
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    solve(root, ans, X);
    return ans;

    //iterative approach
    // int ans = -1;
    // while(root){
    //     int t = root->val;
    //     if(t == x) {
    //         ans= t;
    //         return t;
    //     }

    //     if(t < x) {
    //         ans = t;
    //         root = root->right;
    //     }
    //     else {
    //         root = root->left;
    //     }
    // }
    // return ans;
}