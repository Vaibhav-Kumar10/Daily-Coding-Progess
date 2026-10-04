class Solution {
public:
    /*
    bool checkValidString(string s) {
        int minRange = 0, maxRange = 0;
        for (char ch : s) {
            if (ch == '(') {
                minRange++;
                maxRange++;
            } else if (ch == ')') {
                minRange--;
                maxRange--;
            } else {
                minRange--;
                maxRange++;
            }
            if (minRange < 0) {
                minRange = 0;
            }
            if (maxRange < 0) {
                return false;
            }
        }
        return minRange == 0;
    }
    */
    /*
    bool checkValidString(string s) {
        int n = s.size();
        vector<int> next(n + 1, 0);
        next[0] = 1;
        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> cur(n + 1, 0);
            for (int cnt = 0; cnt < n; cnt++) {
                bool ans = false;
                if (s[ind] == '(') {
                    ans = next[cnt + 1];
                } else if (s[ind] == ')') {
                    ans = (cnt > 0) && (next[cnt - 1]);
                } else {
                    ans = next[cnt + 1] || next[cnt] ||
                          ((cnt > 0) && (next[cnt - 1]));
                }
                cur[cnt] = ans;
            }
            next = cur;
        }
        return next[0];
    }
    */
    /*
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[n][0] = 1;
        for (int cnt = 1; cnt <= n; cnt++) {
            dp[n][cnt] = 0;
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cnt = 0; cnt < n; cnt++) {
                bool ans = false;
                if (s[ind] == '(') {
                    ans = dp[ind + 1][cnt + 1];
                } else if (s[ind] == ')') {
                    ans = (cnt > 0) && (dp[ind + 1][cnt - 1]);
                } else {
                    ans = dp[ind + 1][cnt + 1] || dp[ind + 1][cnt] ||
                          ((cnt > 0) && (dp[ind + 1][cnt - 1]));
                }
                dp[ind][cnt] = ans;
            }
        }
        return dp[0][0];
    }
    */
    // /*
    bool f(string s, int ind, int cnt, int n, vector<vector<int>>& dp) {
        if (cnt < 0) {
            return false;
        }
        if (ind == n) {
            return cnt == 0;
        }
        if (dp[ind][cnt] != -1) {
            return dp[ind][cnt];
        }
        if (s[ind] == '(') {
            return f(s, ind + 1, cnt + 1, n, dp);
        }
        if (s[ind] == ')') {
            return f(s, ind + 1, cnt - 1, n, dp);
        }
        return dp[ind][cnt] = f(s, ind + 1, cnt + 1, n, dp) ||
                              f(s, ind + 1, cnt - 1, n, dp) ||
                              f(s, ind + 1, cnt, n, dp);
    }
    bool checkValidString(string s) {
        int cnt = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(s, 0, cnt, n, dp);
    }
    // */
};