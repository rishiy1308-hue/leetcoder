class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i =0 ;i<n;i++){
            map<int,int> mpp;
            int cnt = 0;
            for(int j = i;j<n;j++){
                if(j == i){
                     cnt++;
                     mpp[nums[j]] = 0;;
                }
                else{
                    if(mpp.find(nums[j])==mpp.end()){
                        cnt++;
                        mpp[nums[j]] = 0;
                    }
                }
                ans += cnt*cnt;
            }
        }
        return ans;
    }
};