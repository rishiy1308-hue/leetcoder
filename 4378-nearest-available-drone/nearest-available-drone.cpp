class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = INT_MAX;
        int n = drones.size();
        int ans = -1;
        for(int i = 0;i<n;i++){
            int t = abs(drones[i][0]-target[0])+ abs(drones[i][1]-target[1]);
            if(t<=drones[i][2]){
                if(t<mini){
                    mini = t;
                    ans = i;
                }
            }
            else continue;
        }
        return ans;
    }
};