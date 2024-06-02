#include<bits/stdc++.h>

using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size(); int k=n-1;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n; j++){
            swap(matrix[i][j], matrix[k-i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
    // Space Complexity: O(1).
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "n";
    }

}

