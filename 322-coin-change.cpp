class Solution {
public:
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
};