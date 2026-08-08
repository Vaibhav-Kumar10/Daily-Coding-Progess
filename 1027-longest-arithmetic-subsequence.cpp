class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int ans = 0;
        // -ve dif also possible
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int dif = nums[i] - nums[j];
                // adding offset bcz => -ve dif also possible
                int d = dif + 500;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
    /*
    int f(int ind, int dif, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind < 0) {
            return 0;
        }
        // adding offset bcz => -ve dif also possible
        int d = dif + 500;
        if (dp[ind][d] != -1) {
            return dp[ind][d];
        }
        int ans = 0;
        for (int i = ind - 1; i >= 0; i--) {
            if (nums[ind] - nums[i] == dif) {
                ans = max(ans, 1 + f(i, dif, nums, dp));
            }
        }
        return dp[ind][d] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int ans = 0;
        // -ve dif also possible
        vector<vector<int>> dp(n, vector<int>(1001, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, 2 + f(i, nums[j] - nums[i], nums, dp));
            }
        }
        return ans;
    }
    */
};