class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(i==0 || i==m-1){
                for(int j = 0;j<n;j++){
                    if(board[i][j]=='O'){
                        q.push({i,j});
                    }
                }
            }
            else{
                if(board[i][0] == 'O') q.push({i,0});
                if(board[i][n-1] == 'O') q.push({i,n-1});
            }
        }
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col]=1;

            if(row-1>=0 && board[row-1][col]=='O' && vis[row-1][col]==0){
                q.push({row-1,col});
                vis[row-1][col]=1;
            }
            if(col+1<n && board[row][col+1]=='O' && vis[row][col+1]==0){
                q.push({row,col+1});
                vis[row][col+1]=1;
            }
            if(row+1<m && board[row+1][col]=='O' && vis[row+1][col]==0){
                q.push({row+1,col});
                vis[row+1][col]=1;
            }
            if(col-1>=0 && board[row][col-1]=='O' && vis[row][col-1]==0){
                q.push({row,col-1});
                vis[row][col-1]=1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
            }
        }
    }
};