class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(), a_1 = 0, a_2 = 0, a_3 = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            // Alice takes 1 stone
            int alice_one_stone = stoneValue[ind];
            // Bob after Alice takes 1 stone
            int bob_after_one_stone = a_1;
            int score_dif = alice_one_stone - bob_after_one_stone;

            // Alice takes 2 stones
            if (ind + 2 <= n) {
                int alice_two_stone = stoneValue[ind] + stoneValue[ind + 1];
                // Bob after Alice takes 2 stones
                int bob_after_two_stone = a_2;

                score_dif =
                    max(score_dif, alice_two_stone - bob_after_two_stone);
            }

            // Alice takes 3 stones
            if (ind + 3 <= n) {
                int alice_three_stone =
                    stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2];
                // Bob after Alice takes 3 stones
                int bob_after_three_stone = a_3;

                score_dif =
                    max(score_dif, alice_three_stone - bob_after_three_stone);
            }
            a_3 = a_2;
            a_2 = a_1;
            a_1 = score_dif;
        }

        int alice_bob_score = a_1;
        if (alice_bob_score > 0) {
            return "Alice";
        } else if (alice_bob_score < 0) {
            return "Bob";
        }
        return "Tie";
    }
    /*
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            // Alice takes 1 stone
            int alice_one_stone = stoneValue[ind];
            // Bob after Alice takes 1 stone
            int bob_after_one_stone = dp[ind + 1];
            int score_dif = alice_one_stone - bob_after_one_stone;

            // Alice takes 2 stones
            if (ind + 2 <= n) {
                int alice_two_stone = stoneValue[ind] + stoneValue[ind + 1];
                // Bob after Alice takes 2 stones
                int bob_after_two_stone = dp[ind + 2];

                score_dif =
                    max(score_dif, alice_two_stone - bob_after_two_stone);
            }

            // Alice takes 3 stones
            if (ind + 3 <= n) {
                int alice_three_stone =
                    stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2];
                // Bob after Alice takes 3 stones
                int bob_after_three_stone = dp[ind + 3];

                score_dif =
                    max(score_dif, alice_three_stone - bob_after_three_stone);
            }

            dp[ind] = score_dif;
        }

        int alice_bob_score = dp[0];
        if (alice_bob_score > 0) {
            return "Alice";
        } else if (alice_bob_score < 0) {
            return "Bob";
        }
        return "Tie";
    }
    */
    /*
    int f(int ind, vector<int>& stoneValue, int n, vector<int>& dp) {
        if (ind >= n) {
            return 0;
        }
        if (dp[ind] != INT_MIN) {
            return dp[ind];
        }

        // Alice takes 1 stone
        int alice_one_stone = stoneValue[ind];
        // Bob after Alice takes 1 stone
        int bob_after_one_stone = f(ind + 1, stoneValue, n, dp);
        int score_dif = alice_one_stone - bob_after_one_stone;

        // Alice takes 2 stones
        if (ind + 1 < n) {
            int alice_two_stone = stoneValue[ind] + stoneValue[ind + 1];
            // Bob after Alice takes 2 stones
            int bob_after_two_stone = f(ind + 2, stoneValue, n, dp);

            score_dif = max(score_dif, alice_two_stone - bob_after_two_stone);
        }

        // Alice takes 3 stones
        if (ind + 2 < n) {
            int alice_three_stone =
                stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2];
            // Bob after Alice takes 3 stones
            int bob_after_three_stone = f(ind + 3, stoneValue, n, dp);

            score_dif =
                max(score_dif, alice_three_stone - bob_after_three_stone);
        }

        return dp[ind] = score_dif;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN);
        int alice_bob_score = f(0, stoneValue, n, dp);
        if (alice_bob_score > 0) {
            return "Alice";
        } else if (alice_bob_score < 0) {
            return "Bob";
        }
        return "Tie";
    }
    */
};