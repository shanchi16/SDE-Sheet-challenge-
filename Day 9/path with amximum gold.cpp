class Solution {
public:
    void dfs(vector<vector<int>>& grid,int& temp, int i, int j, int& maxi,vector<vector<int>>& vis) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==1) return;

        int roww[] = {1, 0, -1, 0};
        int coll[] = {0, -1, 0, 1};
        
        vis[i][j] = 1;
        temp+=grid[i][j];
        maxi = max(maxi,temp);
        // cout<< temp <<","<< grid[i][j]<<" " ;
        for(int k=0; k<4; k++){
            int x=roww[k]+i;
            int y=coll[k]+j;
            dfs(grid, temp, x, y, maxi, vis);
        }
        vis[i][j]=0;
        temp-=grid[i][j];

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    int temp = 0;
                    dfs(grid,temp, i, j, maxi, vis);
                }
            }
        }

        return maxi;
    }
};

