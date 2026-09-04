class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int ans = INT_MAX;
        int idx = -1;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,nums[i]);
            int mini = INT_MAX;
            for(int j = i;j<n;j++) mini = min(mini,nums[j]);
            int stability = maxi-mini;
            ans = min(ans,stability);
            if(ans<=k){
                idx = i;
                break;
            }
        }
        return idx;
    }
};