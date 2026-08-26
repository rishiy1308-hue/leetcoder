class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 2) return nums[1];
        int highest = nums[nums.size()-1];
        int sHighest;
        int i = nums.size()-2;
        while(i>=0 && nums[i] == highest){
            i--;
        }
        if(i>=0) sHighest = nums[i];
        i--;
        while(i>=0 && nums[i] == sHighest){
            i--;
        }
        if(i>=0) return nums[i];
        return highest;
    }
};