class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int n = nums.size();

        while(left < n && right < n) {
            while(left < n && nums[left] % 2 == 0)
                left +=2;
            while(right < n && nums[right] % 2 == 1)
                right += 2;
            if(left < n && right < n)
                swap(nums[left], nums[right]);
        }

        return nums;
    }
};