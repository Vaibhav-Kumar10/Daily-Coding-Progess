class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        queue<tuple<int, int, int>> q;
        // { cur_effort, row, col }
        q.push({0, 0, 0});
        efforts[0][0] = 0;
        while (!q.empty()) {
            auto [cur_effort, row, col] = q.front();
            q.pop();
            if (cur_effort > efforts[row][col]) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }
                int next_effort = abs(heights[row][col] - heights[nr][nc]);
                int maxEffort = max(cur_effort, next_effort);
                if (maxEffort < efforts[nr][nc]) {
                    efforts[nr][nc] = maxEffort;
                    q.push({efforts[nr][nc], nr, nc});
                }
            }
        }
        return efforts[n - 1][m - 1];
    }
    /*
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        // { cur_effort, row, col }
        pq.push({0, 0, 0});
        efforts[0][0] = 0;
        while (!pq.empty()) {
            auto [cur_effort, row, col] = pq.top();
            pq.pop();
            if (cur_effort > efforts[row][col]) {
                continue;
            }
            if (row == n - 1 && col == m - 1) {
                return cur_effort;
            }
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }
                int next_effort = abs(heights[row][col] - heights[nr][nc]);
                int maxEffort = max(cur_effort, next_effort);
                if (maxEffort < efforts[nr][nc]) {
                    efforts[nr][nc] = maxEffort;
                    pq.push({efforts[nr][nc], nr, nc});
                }
            }
        }
        return 0;
    }
    */
};