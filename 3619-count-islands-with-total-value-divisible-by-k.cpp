class Solution {
public:
    long long bfs(int r, int c, vector<vector<int>>& grid,
                  vector<vector<int>>& visited, int n, int m) {
        long long cnt = 0;
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            cnt += grid[row][col];
            vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    grid[nr][nc] != 0 && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return cnt;
    }
    long long dfs(int row, int col, vector<vector<int>>& grid,
                  vector<vector<int>>& visited, int n, int m) {
        long long cnt = grid[row][col];
        visited[row][col] = 1;
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = col + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != 0 &&
                !visited[nr][nc]) {
                cnt += dfs(nr, nc, grid, visited, n, m);
            }
        }
        return cnt;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long totalValue = bfs(i, j, grid, visited, n, m);
                    // long long totalValue = dfs(i, j, grid, visited, n, m);
                    if (totalValue % k == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
