class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]] = i;
            }
            else return true;
        }
        return false;
    }
};