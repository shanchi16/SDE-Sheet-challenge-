class Solution {
public:
    void solve(vector<int> & nums,int ind, vector<vector<int> >& ans, vector<int> & ds){
        ans.push_back(ds);

        for(int i=ind; i<nums.size(); i++){
            if(i!=ind && nums[i] == nums[i-1]) continue;

            ds.push_back(nums[i]);
            solve(nums, i+1, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        vector<int> ds;
        solve(nums, 0, ans, ds);
        
        return ans;
    }
};