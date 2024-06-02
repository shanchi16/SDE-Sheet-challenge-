#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& inter) {
    sort(inter.begin(), inter.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    int st = inter[0][0], end = inter[0][1];

    vector<vector<int>> ans;
    int n = inter.size();
    for(int i=1; i<n; i++){
        if(end >= inter[i][0]){
            end = max(end , inter[i][1]);
        }else{
            ans.push_back({st, end});
            st = inter[i][0];
            end = inter[i][1];
        }
    }
    ans.push_back({st, end});
    return ans;
    // Time Complexity: O(N*logN) + O(N)
    // Space Complexity: O(N)
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = merge(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

