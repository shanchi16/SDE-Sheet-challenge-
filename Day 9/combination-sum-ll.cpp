class Solution {
public:

    void solve(vector<int>& c, int target, set<vector<int>>& s, int i, vector<int>& out){
        if(target == 0){
            s.insert(out);
            return;
        }
        if(i >= c.size() || target<0) return;

        if(c[i] <= target){
            out.push_back(c[i]);
            solve(c, target-c[i], s, i+1, out);
            out.pop_back();
        }

        while(i<c.size()-1 && c[i] == c[i+1]) i++;
        solve(c, target, s, i+1, out);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        set<vector<int> > s;
        vector<int> out;
        solve(c, t, s, 0, out);

        vector<vector<int>> ans;
        for(auto it:s) ans.push_back(it);
        return ans;
    }
};