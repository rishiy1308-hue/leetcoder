class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;

        for(int i = 0; i < img1.size(); i++) {
            for(int j = 0; j < img1[0].size(); j++) {
                if(img1[i][j] == 1)
                    v1.push_back({i,j});
            }
        }

        for(int i = 0; i < img2.size(); i++) {
            for(int j = 0; j < img2[0].size(); j++) {
                if(img2[i][j] == 1)
                    v2.push_back({i,j});
            }
        }

        if(v1.empty() || v2.empty()) return 0;

        map<pair<int,int>, int> distance;

        for(auto it : v1) {
            for(auto it1 : v2) {

                int dx = it1.first - it.first;
                int dy = it1.second - it.second;

                distance[{dx,dy}]++;
            }
        }

        int maxi = 0;

        for(auto it : distance) {
            maxi = max(maxi, it.second);
        }

        return maxi;
    }
};