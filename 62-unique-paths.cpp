class Solution {
public:
    int f(int cur_x, int cur_y, int m, int n, vector<vector<int>>& dp) {
        if (cur_x == m - 1 && cur_y == n - 1) {
            return 1;
        }
        if (cur_x >= m || cur_y >= n) {
            return 0;
        }
        if (dp[cur_x][cur_y] != -1) {
            return dp[cur_x][cur_y];
        }
        // Go right
        int left = f(cur_x, cur_y + 1, m, n, dp);
        // Go down
        int down = f(cur_x + 1, cur_y, m, n, dp);
        return dp[cur_x][cur_y] = left + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
};