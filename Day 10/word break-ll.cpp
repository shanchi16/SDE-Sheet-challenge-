#include <bits/stdc++.h> 

void solve(int i, string &s, vector<string> &dictionary, unordered_map<string, int>& mp,vector<string>& result, string& ans){
    if(i==s.size()) {
        result.push_back(ans);
        return;
    }

    for(int k=i; k<s.size(); k++){
        
        int t=k-i+1;
        string st = s.substr(i,t );
        if(mp.find(st) != mp.end()){
            if(ans.size() == 0) ans+=st;
            else {
                ans+=" ";
                ans+=st;
            }
            solve(k+1, s, dictionary, mp,result, ans);
            while(t--) ans.pop_back();
            if(ans.size() > 0) ans.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> result;
    string ans;
    unordered_map<string, int> mp;
    for(auto it:dictionary){
        mp[it] = 1;
    }

    solve(0, s,dictionary, mp, result,ans);
    return result;

}