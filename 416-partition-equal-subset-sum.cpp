class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int a : nums) {
            sum += a;
        }
        if (sum % 2 == 1) {
            return false;
        }
        return isSubsetSum(nums, sum / 2);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            vector<bool> cur(sum + 1, false);
            cur[0] = true;
            for (int t = 1; t <= sum; t++) {
                bool not_take = prev[t];
                bool take = false;
                if (t >= arr[i]) {
                    take = prev[t - arr[i]];
                }
                cur[t] = take || not_take;
            }
            prev = cur;
        }
        return prev[sum];
    }
    /*
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;

        for(int i = 1; i < n; i++) {
            for(int t = 1; t <= sum; t++) {
                bool not_take = dp[i - 1][t];
                bool take = false;
                if(t >= arr[i]) {
                    take = dp[i - 1][t - arr[i]];
                }
                dp[i][t] = take || not_take;
            }
        }
        return dp[n - 1][sum];
    }
    */
    /*
    bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if(target == 0) {
            return true;
        }
        if(ind == 0) {
            return target == arr[ind];
        }

        if(dp[ind][target] != -1) {
            return dp[ind][target];
        }

        bool not_take = f(ind - 1, target, arr, dp);
        bool take = false;
        if(target >= arr[ind]) {
            take = f(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
    */
};