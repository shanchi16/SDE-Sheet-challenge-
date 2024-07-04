class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        vector<vector<int>> img;
        int n=image.size(), m = image[0].size();
        img = image;
        int dx[] = {0, -1, 0, 1};
        int dy[] = {1, 0, -1, 0};
        int clr = image[sr][sc];

        queue<pair<int, int> > q;
        q.push({sr,sc});
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i=top.first, j = top.second;
            img[i][j] = color;

            for(int k=0; k<4; k++){
                int x = i+dx[k], y=j+dy[k];
                if(x >=0 && x<n && y>=0 && y<m && img[x][y] == clr && img[x][y] != color) q.push({x,y});
            }
        }

        return img;

    }
}; 