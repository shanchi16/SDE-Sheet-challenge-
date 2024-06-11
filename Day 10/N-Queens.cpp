class Solution {
public:

    bool isSafe(vector<string>& board, int i, int j, int n){
        // check row
        for(int k=0; k<j; k++){
            if(board[i][k] == 'Q') return false;
        }

        // check col
        for(int k=0; k<i; k++){
            if(board[k][j] == 'Q') return false;
        }

        // check diagnols
        int x=i, y=j;
        while(x>=0 && y>=0){
            if(board[x][y] == 'Q') return false;
            x--, y--;
        }
        
        // check diagnols
        x=i, y=j;
        while(x >=0 && y<n){
            if(board[x][y] == 'Q') return false;
            x--, y++;
        }

        return true;
    }

    void solve(vector<string>& board, int i, int n, vector<vector<string>>& ans){
        if(i==n) {
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++){
            if(isSafe(board, i, j, n)){
                board[i][j] = 'Q';
                solve(board, i+1, n, ans);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s;
        for(int i=0; i<n; i++){
            s+='.';
        }
        for(int i=0; i<n; i++) board.push_back(s);

        vector<vector<string>> ans;

        solve(board,0,n,ans);

        return ans;
    }
};