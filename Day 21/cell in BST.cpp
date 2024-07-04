
int findCeil(BinaryTreeNode<int> *root, int x){
    int ans = INT_MAX;
    while(root){
        int t = root->data;
        if(t == x ) {
            return t;;
        }
        if(t < x){
            root = root->right;
        }
        else {
            ans = t;
            root = root->left;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}