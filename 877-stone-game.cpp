class Solution {
public:
    int f(int left, int right, vector<int>& piles, int n,
          vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        // Alice take left
        int take_left = piles[left];
        int l_bob_take_left = f(left + 2, right, piles, n, dp);
        int l_bob_take_right = f(left + 1, right - 1, piles, n, dp);
        take_left += min(l_bob_take_left, l_bob_take_right);

        // Alice take right
        int take_right = piles[right];
        int r_bob_take_left = f(left + 1, right - 1, piles, n, dp);
        int r_bob_take_right = f(left, right - 2, piles, n, dp);
        take_right += min(r_bob_take_left, r_bob_take_right);

        return dp[left][right] = max(take_left, take_right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), total_stones = 0;
        for (int stone : piles) {
            total_stones += stone;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int alice_score = f(0, n - 1, piles, n, dp);
        return alice_score > total_stones / 2;
    }
};