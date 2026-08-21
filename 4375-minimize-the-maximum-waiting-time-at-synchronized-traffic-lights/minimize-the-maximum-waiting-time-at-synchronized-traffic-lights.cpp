class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxel = INT_MIN;
        for(int i = 0;i<lights.size();i++){
            maxel = max(maxel,lights[i]);
        }
        int maxi = 0;
        for(int i = 0;i<arrivalTime.size();i++){
            int r = arrivalTime[i]%period;
            if(r>=maxel){
                maxi = max(maxi,period-r);
            }
            else continue;
        }
        return maxi;
    }
};