class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int amnt = 0; amnt <= amount; amnt++) {
            // can first coin be used for remaining amount
            if (amnt % coins[0] == 0) {
                dp[0][amnt] = amnt / coins[0];
            } else {
                dp[0][amnt] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                // Skip current coin
                int not_take = dp[i - 1][t];
                // Use current coin once
                int take = t >= coins[i] ? 1 + dp[i][t - coins[i]] : 1e9;
                dp[i][t] = min(take, not_take);
            }
        }

        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
    /*
    int f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (ind == 0) {
            // can first coin be used for remaining amount
            if (target % arr[ind] == 0) {
                return target / arr[ind];
            }
            return 1e9;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        // Skip current coin
        int not_take = f(ind - 1, target, arr, dp);

        // Use current coin once
        int take =
            arr[ind] <= target ? 1 + f(ind, target - arr[ind], arr, dp) : 1e9;

        return dp[ind][target] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ind = n - 1;
        int minCoins = f(ind, amount, coins, dp);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
    */
};