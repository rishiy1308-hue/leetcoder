class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;

        // Start BFS from all 0's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            dist[row][col] = steps;

            if(row - 1 >= 0 && vis[row - 1][col] == 0) {
                q.push({{row - 1, col}, steps + 1});
                vis[row - 1][col] = 1;
            }

            if(col + 1 < m && vis[row][col + 1] == 0) {
                q.push({{row, col + 1}, steps + 1});
                vis[row][col + 1] = 1;
            }

            if(row + 1 < n && vis[row + 1][col] == 0) {
                q.push({{row + 1, col}, steps + 1});
                vis[row + 1][col] = 1;
            }

            if(col - 1 >= 0 && vis[row][col - 1] == 0) {
                q.push({{row, col - 1}, steps + 1});
                vis[row][col - 1] = 1;
            }
        }

        return dist;
    }
};