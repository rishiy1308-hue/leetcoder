class Solution {
public:
    void bfs(int sr,int sc,int originalColor,int color, vector<vector<int>>& image,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        image[sr][sc]=color;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row-1>=0 && image[row-1][col]==originalColor && vis[row-1][col]==0){
                q.push({row-1,col});
                vis[row-1][col]=1;
                image[row-1][col]=color;
            }
            if(row+1<image.size() && image[row+1][col]==originalColor && vis[row+1][col]==0){
                q.push({row+1,col});
                vis[row+1][col]=1;
                image[row+1][col]=color;
            }
            if(col-1>=0 && image[row][col-1]==originalColor && vis[row][col-1]==0){
                q.push({row,col-1});
                vis[row][col-1]=1;
                image[row][col-1]=color;
            }
            if(col+1<image[0].size() && image[row][col+1]==originalColor && vis[row][col+1]==0){
                q.push({row,col+1});
                vis[row][col+1]=1;
                image[row][col+1]=color;
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bfs(sr,sc,image[sr][sc],color,image,vis);
        return image;
    }
};