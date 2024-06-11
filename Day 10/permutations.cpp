class Solution {
public:
    void solve(vector<int>& nums, int i, int n, vector<int>& ds, vector<vector<int> >& ans){
        if( ds.size() == n ) {
            ans.push_back(ds);
            return;
        }

        for(int k=0; k<n; k++){
            if(nums[k] != INT_MAX){
                int temp = nums[k];
                nums[k] = INT_MAX;
                ds.push_back(temp);
                solve(nums,k+1, n, ds,ans);
                nums[k] = temp;
                ds.pop_back();
            }
        }
        // Time complexity = O(N! * N)
        // space Complexity = O(N)

    }
    void solve2(vector<int>& nums, int i, int n, vector<vector<int> >& ans){
        if(i==n) {
            ans.push_back(nums);
            return;
        }

        for(int k=i; k<n; k++){
            swap(nums[i], nums[k]);
            solve2(nums, i+1, n,ans);
            swap(nums[i], nums[k]);
        }
        // time complexity = O(n! * n);
        // space complexit = O(1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();

        vector<int> vis(n, 0);
        vector<int> ds;
        vector<vector<int> > ans;
        solve(nums, 0, n, ds, ans);
        return ans;
    }
};