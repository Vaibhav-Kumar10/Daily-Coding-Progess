class Solution {
public:
    int numberOfIslands(vector<vector<int>> grid, int n, int m) {
        int islands = 0;
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = row + dr[k], nc = col + dc[k];
                            if (nr < 0 || nr >= n || nc < 0 || nc >= m ||
                                grid[nr][nc] == 0) {
                                continue;
                            }
                            grid[nr][nc] = 0;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int num_islands = numberOfIslands(grid, n, m);
        if (num_islands != 1) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int num_islands = numberOfIslands(grid, n, m);
                    if (num_islands != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};