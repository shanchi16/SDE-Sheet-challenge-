class Solution {
public:
    bool palin(string st){
        int i=0; int j=st.size()-1;
        while(i<=j){
            if(st[i] != st[j]) return false;
            i++; j--;
        }
        return true;
    }

    void solve(string& s, int i, vector<vector<string>>& ans, vector<string>& op){
        
        int n=s.size();
        if(i>n ) return;

        if(i == n) {
            ans.push_back(op);
            return;
        }
        for(int k=i; k<n; k++){
            string t = s.substr(i, k-i+1 );
            if(palin(t)){
                op.push_back(t);
                solve(s, k+1, ans, op);
                op.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> op;
        int n = s.size();
        solve(s, 0, ans, op);

        return ans;
    }
};