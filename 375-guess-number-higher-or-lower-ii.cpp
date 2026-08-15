class Solution {
public:
    int f(int start, int end, vector<vector<int>>& dp) {
        if (start >= end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(f(start, i - 1, dp), f(i + 1, end, dp)));
        }
        return dp[start][end] = ans;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(1 + n, vector<int>(n + 1, -1));
        return f(1, n, dp);
    }
};