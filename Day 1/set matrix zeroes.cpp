#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void zeroMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<pair<int, int>> zeros;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                zeros.push_back({i, j});
            }
        }
    }
    for(auto it:zeros){
        int x = it.first;
        int y = it.second;
        for(int j=0; j<m; j++) matrix[x][j]=0;
        for(int i=0; i<n; i++) matrix[i][y]=0;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};.
    zeroMatrix(matrix);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}

