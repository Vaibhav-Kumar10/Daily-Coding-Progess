class Solution {
public:
    vector<vector<int>> dp;
    bool f(int ind, int k, vector<int>& stones,
           unordered_map<int, int>& stone_idx, int n) {
        if (ind == n - 1) {
            return true;
        }
        if (dp[ind][k] != -1) {
            return dp[ind][k];
        }
        bool can_cross = false;
        for (int next_k = k - 1; next_k <= k + 1; next_k++) {
            if (next_k <= 0) {
                continue;
            }
            int next_stone = stones[ind] + next_k;
            if (stone_idx.find(next_stone) != stone_idx.end()) {
                int next_stone_idx = stone_idx[next_stone];
                can_cross = can_cross ||
                            f(next_stone_idx, next_k, stones, stone_idx, n);
            }
        }
        return dp[ind][k] = can_cross;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) {
            return false;
        }
        unordered_map<int, int> stone_idx;
        for (int i = 0; i < n; i++) {
            stone_idx[stones[i]] = i;
        }
        int k = 0, ind = 0;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return f(ind, k, stones, stone_idx, n);
    }
    /*
    bool f(int cur_stone, int k, vector<int>& stones,
           unordered_map<int, int>& stone_idx, int n,
           map<pair<int, int>, bool>& dp) {
        if (stone_idx.find(cur_stone) == stone_idx.end()) {
            return false;
        }
        int ind = stone_idx[cur_stone];
        if (ind == n - 1) {
            return true;
        }
        if (dp.find({cur_stone, k}) != dp.end()) {
            return dp[{cur_stone, k}];
        }

        // k - 1 jump
        bool k_1_jump =
            k - 1 > 0 ? f(cur_stone + k - 1, k - 1, stones, stone_idx, n, dp)
                      : false;

        // k jump
        bool k_jump = f(cur_stone + k, k, stones, stone_idx, n, dp);

        // k + 1 jump
        bool k__1_jump = f(cur_stone + k + 1, k + 1, stones, stone_idx, n, dp);

        return dp[{cur_stone, k}] = k_1_jump || k_jump || k__1_jump;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, int> stone_idx;
        for (int i = 0; i < n; i++) {
            stone_idx[stones[i]] = i;
        }
        map<pair<int, int>, bool> dp;
        int k = 1, cur_stone = stones[0] + 1;
        return f(cur_stone, k, stones, stone_idx, n, dp);
    }
    */
};