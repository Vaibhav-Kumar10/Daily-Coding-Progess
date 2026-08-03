class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minHeap;
        set<pair<int, int>> visited;
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        minHeap.push({grid[0][0], 0, 0});
        visited.insert({0, 0});
        while (!minHeap.empty()) {
            auto [cur_depth, row, col] = minHeap.top();
            minHeap.pop();
            if (row == n - 1 && col == m - 1) {
                return cur_depth;
            }
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                    visited.find({nr, nc}) != visited.end()) {
                    continue;
                }
                int new_depth = max(cur_depth, grid[nr][nc]);
                visited.insert({nr, nc});
                minHeap.push({new_depth, nr, nc});
            }
        }
        return -1;
    }
};