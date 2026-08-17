class Solution {
public:
    // /*
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        vector<int> t(40, 0);
        t[0] = 0, t[1] = 1, t[2] = 1;
        for (int i = 3; i <= n; i++) {
            t[i] = t[i - 1] + t[i - 2] + t[i - 3];
        }
        return t[n];
    }
    // */
    /*
    int t(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = t(n - 1, dp) + t(n - 2, dp) + t(n - 3, dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return t(n, dp);
    }
    */
    /*
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
    */
};