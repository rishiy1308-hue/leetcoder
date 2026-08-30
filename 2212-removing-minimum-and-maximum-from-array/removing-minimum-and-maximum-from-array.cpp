class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        int n = nums.size();

        int maxi = INT_MIN, mini = INT_MAX;
        int idx1 = -1, idx2 = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                idx1 = i;
            }

            if(nums[i] < mini) {
                mini = nums[i];
                idx2 = i;
            }
        }

        int nop1 = max(idx1, idx2) + 1;

        int nop2 = n - min(idx1, idx2);

        int nop3 = (idx1 + 1) + (n - idx2);

        int nop4 = (idx2 + 1) + (n - idx1);

        return min({nop1, nop2, nop3, nop4});
    }
};