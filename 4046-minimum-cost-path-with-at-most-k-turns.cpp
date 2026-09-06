class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1) {
            return grid[0][0];
        }
        using State = tuple<int, int, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        vector<vector<vector<vector<int>>>> cost(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(k + 1, vector<int>(5, INT_MAX))));

        // 0 = right, 1 = down, 2 = left, 3 = up
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        pq.push({grid[0][0], 0, 0, 0, 4});
        cost[0][0][0][4] = grid[0][0];

        while (!pq.empty()) {
            auto [cur_cost, turns, row, col, cur_dir] = pq.top();
            pq.pop();
            if (cur_cost > cost[row][col][turns][cur_dir]) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }

                int next_turns = turns;
                if (cur_dir != 4 && cur_dir != i) {
                    next_turns++;
                }
                if (next_turns > k) {
                    continue;
                }

                int new_cost = cur_cost + grid[nr][nc];
                if (new_cost < cost[nr][nc][next_turns][i]) {
                    cost[nr][nc][next_turns][i] = new_cost;
                    pq.push(
                        {cost[nr][nc][next_turns][i], next_turns, nr, nc, i});
                }
            }
        }
        int min_cost = INT_MAX;
        for (int turn = 0; turn <= k; turn++) {
            for (int dir = 0; dir < 4; dir++) {
                min_cost = min(min_cost, cost[n - 1][m - 1][turn][dir]);
            }
        }
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};