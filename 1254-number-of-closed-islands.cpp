class Solution {
public:
    bool bfs(int x, int y, int n, int m, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        vector<int> dr = {0, 1, 0, -1}, dc = {-1, 0, 1, 0};
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 2;
        bool isClosed = true;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                // out of the grid or border cell
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    isClosed = false;
                }
                // within the grid only
                else if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (bfs(i, j, n, m, grid, visited)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};