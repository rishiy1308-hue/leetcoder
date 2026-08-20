class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2;i<n;i++){
            int s1 = arr1.size();
            int s2 = arr2.size();
            if(arr1[s1-1]>arr2[s2-1]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        vector<int> ans(n);
        int j = 0;
        for(int i = 0;i<n;i++){
            if(i<arr1.size()){
                ans[i] = arr1[i];
                continue;
            }
            else{
                ans[i] = arr2[j];
                j++;
            }
        }
        return ans;
    }
};