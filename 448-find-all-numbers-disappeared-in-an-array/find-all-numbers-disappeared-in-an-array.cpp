class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]]++;
            }
        }
        vector<int> ans;
        for(int i = 1;i<=nums.size();i++){
            if(mpp.find(i) == mpp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};