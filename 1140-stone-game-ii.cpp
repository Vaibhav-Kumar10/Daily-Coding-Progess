class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int player, int ind, int m, vector<int>& piles, int n) {
        // Not possible to choose for alice
        if (ind >= n) {
            return 0;
        }
        if (dp[player][ind][m] != -1) {
            return dp[player][ind][m];
        }
        int player_stones = 0, ans = player == 1 ? INT_MIN : INT_MAX;
        // Alice take x piles,
        // bob gets to choose max(m, x) piles from n - x piles
        for (int x = 1; x <= min(n - ind, 2 * m); x++) {
            player_stones += piles[ind + x - 1];
            int opponent_stones = f(!player, ind + x, max(m, x), piles, n);
            // Alice turn
            if (player == 1) {
                ans = max(ans, player_stones + opponent_stones);
            }
            // Bob turn
            else {
                ans = min(ans, opponent_stones);
            }
        }
        return dp[player][ind][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        // Player 1 = Alice, Player 0 = Bob
        int n = piles.size(), m = 1, ind = 0, player = 1;
        dp.assign(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return f(player, ind, m, piles, n);
    }
    /*
    int f(int player, int ind, int m, vector<int>& piles, int n) {
        // Not possible to choose for alice
        if (ind >= n) {
            return 0;
        }
        int player_stones = 0, ans = player == 1 ? INT_MIN : INT_MAX;
        // Alice take i piles,
        // bob gets to choose max(m, i) piles from n - i piles
        for (int i = 0; i < min(n - ind, 2 * m); i++) {
            player_stones += piles[ind + i];
            int opponent_stones =
                f(!player, ind + i + 1, max(m, i + 1), piles, n);
            // Alice turn
            if (player == 1) {
                ans = max(ans, player_stones + opponent_stones);
            }
            // Bob turn
            else {
                ans = min(ans, opponent_stones);
            }
        }
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        // Player 1 = Alice, Player 0 = Bob
        int n = piles.size(), m = 1, ind = 0, player = 1;
        return f(player, ind, m, piles, n);
    }
    */
};
