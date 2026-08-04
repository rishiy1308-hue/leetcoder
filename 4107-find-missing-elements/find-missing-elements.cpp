class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int idx=nums[0];
        for(int i=0;i<nums.size();i++){
            if(idx==nums[i]){
                idx=nums[i]+1;
            }
            else{
                while(idx!=nums[i]){
                    ans.push_back(idx);
                    idx++;
                }
                idx++;
            }
        }
        return ans;
    }
};