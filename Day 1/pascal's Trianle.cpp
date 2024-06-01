#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pascalTriangle(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});
    if(numRows <=1) return ans;
    for(int i=1; i<numRows; i++){
        vector<int> v(i+1);
        v[0] = ans[i-1][0];
        v[i] = ans[i-1][i-1];
        for(int k=1; k<i; k++){
            v[k] = ans[i-1][k-1] + ans[i-1][k];
        }
        ans.push_back(v);
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}