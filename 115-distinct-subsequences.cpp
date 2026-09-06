class Solution {
public:
    int f(int i, int j, string& s, int n, string& t, int m,
          vector<vector<int>>& dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int match = 0;
        if (s[i] == t[j]) {
            match = f(i - 1, j - 1, s, n, t, m, dp);
        }
        int not_match = f(i - 1, j, s, n, t, m, dp);
        int ans = match + not_match;
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int i = n - 1, j = m - 1;
        return f(i, j, s, n, t, m, dp);
    }
};