class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), len = n + m - 1;
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(' || len % 2 == 1) {
            return false;
        }
        vector<int> dr = {0, 1}, dc = {1, 0};
        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(m, vector<bool>(len + 1, false)));
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        visited[0][0][1] = true;
        while (!q.empty()) {
            auto [row, col, cnt] = q.front();
            q.pop();
            if (cnt < 0) {
                continue;
            }
            if (row == n - 1 && col == m - 1) {
                if (cnt == 0) {
                    return true;
                }
                continue;
            }
            for (int i = 0; i < 2; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr >= n || nc >= m) {
                    continue;
                }
                int newCnt = cnt + (grid[nr][nc] == '(' ? 1 : -1);
                if (newCnt < 0) {
                    continue;
                }
                if (visited[nr][nc][newCnt]) {
                    continue;
                }
                visited[nr][nc][newCnt] = true;
                q.push({nr, nc, newCnt});
            }
        }
        return false;
    }
};