class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = INT_MAX;
        vector<vector<unordered_set<int>>> xorDP(n,
                                                 vector<unordered_set<int>>(m));
        xorDP[0][0].insert(grid[0][0]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i != 0) {
                    for (auto eachXor : xorDP[i - 1][j]) {
                        xorDP[i][j].insert(eachXor ^ grid[i][j]);
                    }
                }
                if (j != 0) {
                    for (auto eachXor : xorDP[i][j - 1]) {
                        xorDP[i][j].insert(eachXor ^ grid[i][j]);
                    }
                }
            }
        }
        for (auto eachXor : xorDP[n - 1][m - 1]) {
            ans = min(ans, eachXor);
        }
        return ans;
    }
};
