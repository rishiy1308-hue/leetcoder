class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,int (&vis)[300][300] ){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int frow = q.front().first;
            int fcol = q.front().second;
            q.pop();
            // Left
if ((fcol - 1) >= 0 && grid[frow][fcol - 1] == '1' && vis[frow][fcol - 1] == 0) {
    q.push({frow, fcol - 1});
    vis[frow][fcol - 1] = 1;
}

// Right
if ((fcol + 1) < grid[0].size() && grid[frow][fcol + 1] == '1' && vis[frow][fcol + 1] == 0) {
    q.push({frow, fcol + 1});
    vis[frow][fcol + 1] = 1;
}

// Up
if ((frow - 1) >= 0 && grid[frow - 1][fcol] == '1' && vis[frow - 1][fcol] == 0) {
    q.push({frow - 1, fcol});
    vis[frow - 1][fcol] = 1;
}

// Down
if ((frow + 1) < grid.size() && grid[frow + 1][fcol] == '1' && vis[frow + 1][fcol] == 0) {
    q.push({frow + 1, fcol});
    vis[frow + 1][fcol] = 1;
}




        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        const int MAX = 300;
        int vis[MAX][MAX] = {0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};