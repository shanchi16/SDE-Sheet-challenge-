vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    vector<int> ans;
    int n = A.size();
    if(B > n) return ans;
    int l=0, r=0;
    B--;
    while(B--){
        mp[A[r++]]++;
    }
    while(r < n){
        mp[A[r]]++;
        ans.push_back(mp.size());
        if(mp[A[l]] ==1) mp.erase(A[l]);
        else mp[A[l]]--;
        l++, r++;
    }
    return ans;
}
