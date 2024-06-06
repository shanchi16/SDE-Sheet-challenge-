
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n = matrix[0].size();
    int low = 0;
    int high = m*n-1;

    // apply binary search
    while(low <= high){
        int mid = low + (high-low)/2;
        int x = mid/n, y = mid%n;
        if(matrix[x][y] == target) return true;
        if(matrix[x][y] > target) high = mid-1;
        else low = mid+1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

