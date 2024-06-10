class Solution {
public:

    void solve(vector<int>& c, int target, int i, set<vector<int> >& ans, vector<int>& op){
        if(i >= c.size() || target<0) return ;
        if(target == 0) {
            ans.insert(op);
            return;
        }
        
        solve(c, target, i+1, ans, op);
        if(c[i] <= target){
            op.push_back(c[i]);
            solve(c, target-c[i], i, ans, op);
            op.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        set<vector<int> > ans;
        vector<int> op;
        solve(c, target, 0, ans, op);
        vector<vector<int>> result;
        for(auto it:ans) result.push_back(it);
        return result;
    }
};