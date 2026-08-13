class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int idx = 0;
        for(int i= 0;i<nums.size();i++){
            if(idx == nums[i]){
                idx++;
            }
            else break;
        }
        return idx;
    }
};