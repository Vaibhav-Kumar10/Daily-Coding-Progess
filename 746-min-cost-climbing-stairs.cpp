class Solution {
public:
    int f(int ind, vector<int>& cost, int n, vector<int>& dp) {
        if (ind <= 1) {
            return cost[ind];
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        // one step
        int one_step = cost[ind] + f(ind - 1, cost, n, dp);
        // two step
        int two_step = cost[ind] + f(ind - 2, cost, n, dp);
        return dp[ind] = min(one_step, two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(f(n - 1, cost, n, dp), f(n - 2, cost, n, dp));
    }
};