class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int> > > q;
        vector<vector<int> > box = grid;

        int ansTime =0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(box[i][j] == 2)
                    q.push({0, {i,j}});
            }
        }

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int x = front.second.first;
            int y = front.second.second;
            int time = front.first;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i = 0; i<4; i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx>=0 && newx<box.size() && newy>=0 && newy<box[0].size() && box[newx][newy]==1){
                    pair<int, int> newco = make_pair(newx,newy);
                    q.push({time+1, {newx, newy}});
                    box[newx][newy] = 2;
                    ansTime = max(time+1, ansTime);
                }
            }
        }

        for(int i = 0; i<box.size(); i++){
            for(int j = 0; j<box[0].size(); j++){
                if(box[i][j] == 1) return -1;
            }
        }

        return ansTime;

    }
};