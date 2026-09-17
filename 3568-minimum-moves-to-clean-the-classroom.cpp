class Solution {
public:
    struct State {
        int row, col, e, lbm;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(), m = classroom[0].size();
        map<pair<int, int>, int> litter_pos;
        int litter_cnt = 0, start_row, start_col;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    start_row = i;
                    start_col = j;
                } else if (classroom[i][j] == 'L') {
                    litter_pos[{i, j}] = litter_cnt;
                    litter_cnt++;
                }
            }
        }
        if (litter_cnt == 0) {
            return 0;
        }
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        int total_litter_mask = (1 << litter_cnt) - 1;
        queue<State> q;
        bool visited[n + 1][m + 1][energy + 1][total_litter_mask + 1];
        memset(visited, false, sizeof(visited));
        q.push({start_row, start_col, energy, 0});
        visited[start_row][start_col][energy][0] = true;
        int moves = 0;
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                auto cur_state = q.front();
                q.pop();
                if (cur_state.lbm == total_litter_mask) {
                    return moves;
                }
                if (cur_state.e == 0) {
                    continue;
                }
                for (int i = 0; i < 4; i++) {
                    int nr = cur_state.row + dr[i], nc = cur_state.col + dc[i];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }
                    char next_cell = classroom[nr][nc];
                    int next_energy = cur_state.e - 1;
                    int next_mask = cur_state.lbm;
                    if (next_cell == 'R') {
                        next_energy = energy;
                    } else if (next_cell == 'L') {
                        int next_litter_pos = litter_pos[{nr, nc}];
                        next_mask |= (1 << next_litter_pos);
                    }
                    if (!visited[nr][nc][next_energy][next_mask]) {
                        visited[nr][nc][next_energy][next_mask] = true;
                        q.push({nr, nc, next_energy, next_mask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};