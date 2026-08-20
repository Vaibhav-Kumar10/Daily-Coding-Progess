class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), cost_2 = cost[0], cost_1 = cost[1];
        for (int ind = 2; ind < n; ind++) {
            // one step
            int one_step = cost[ind] + cost_1;
            // two step
            int two_step = cost[ind] + cost_2;
            int cur_cost = min(one_step, two_step);
            cost_2 = cost_1;
            cost_1 = cur_cost;
        }
        return min(cost_1, cost_2);
    }
    /*
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int ind = 2; ind < n; ind++) {
            // one step
            int one_step = cost[ind] + dp[ind - 1];
            // two step
            int two_step = cost[ind] + dp[ind - 2];
            dp[ind] = min(one_step, two_step);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
    */
    /*
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
    */
};