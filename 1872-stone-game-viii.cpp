class Solution {
public:
    int f(int ind, vector<int>& prefixSum_score, int n, vector<int>& dp) {
        if (ind == n - 1) {
            return prefixSum_score[ind];
        }
        if (dp[ind] != INT_MIN) {
            return dp[ind];
        }
        int player_take = prefixSum_score[ind];
        int opponent_score = f(ind + 1, prefixSum_score, n, dp);
        int player_skip = f(ind + 1, prefixSum_score, n, dp);

        return dp[ind] = max(player_take - opponent_score, player_skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum_score(n, 0);
        // When taking i + 1 stones => player gets the score
        // directly using prefoxSum => bcz, it stores the sum of all prev stones
        prefixSum_score[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum_score[i] = prefixSum_score[i - 1] + stones[i];
        }
        vector<int> dp(n + 1, INT_MIN);
        // Start with Alice
        return f(1, prefixSum_score, n, dp);
    }
};