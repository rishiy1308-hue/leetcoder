class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(i==0 || i==m-1){
                for(int j = 0;j<n;j++){
                    if(grid[i][j]==1){
                        q.push({i,j});
                    }
                }
            }
            else{
                if(grid[i][0] == 1) q.push({i,0});
                if(grid[i][n-1] == 1) q.push({i,n-1});
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col]=1;

            if(row-1>=0 && grid[row-1][col]==1 && vis[row-1][col]==0){
                q.push({row-1,col});
                vis[row-1][col]=1;
            }
            if(col+1<n && grid[row][col+1]==1 && vis[row][col+1]==0){
                q.push({row,col+1});
                vis[row][col+1]=1;
            }
            if(row+1<m && grid[row+1][col]==1 && vis[row+1][col]==0){
                q.push({row+1,col});
                vis[row+1][col]=1;
            }
            if(col-1>=0 && grid[row][col-1]==1 && vis[row][col-1]==0){
                q.push({row,col-1});
                vis[row][col-1]=1;
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0) cnt++;
            }
        }
        return cnt;
    }
};