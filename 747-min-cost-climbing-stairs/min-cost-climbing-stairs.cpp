class Solution {
public:
    int steps(vector<int>& cost, int stIdx, vector<int>& dp) {
        if(stIdx >= cost.size())
            return 0;

        if(dp[stIdx] != -1)
            return dp[stIdx];

        dp[stIdx] = cost[stIdx] + min(
            steps(cost, stIdx + 1, dp),
            steps(cost, stIdx + 2, dp)
        );

        return dp[stIdx];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(
            steps(cost, 0, dp),
            steps(cost, 1, dp)
        );
    }
};