class Solution {
public:
    bool winnerSquareGame(int n) {
        int available_stones = n;
        vector<bool> dp(n + 1, false);

        for (int available_stones = 0; available_stones <= n;
             available_stones++) {

            for (int possible_stones = 1;
                 possible_stones * possible_stones <= available_stones;
                 possible_stones++) {

                // Check if opponent can win,
                // when current player takes possible_stones^2 stones
                if (dp[available_stones - possible_stones * possible_stones] ==
                    false) {
                    // Current player wins
                    dp[available_stones] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
    /*
    bool canWin(int available_stones, vector<int>& dp) {
        if (available_stones == 0) {
            return false;
        }
        if (dp[available_stones] != -1) {
            return dp[available_stones];
        }
        for (int possible_stones = 1;
             possible_stones * possible_stones <= available_stones;
             possible_stones++) {
            // Check if opponent can win,
            // when current player takes possible_stones^2 stones
            if (canWin(available_stones - possible_stones * possible_stones,
                       dp) == false) {
                // Current player wins
                return dp[available_stones] = true;
            }
        }
        // Current player can't win
        return dp[available_stones] = false;
    }
    bool winnerSquareGame(int n) {
        int available_stones = n;
        vector<int> dp(n + 1, -1);
        // Call for Alice
        return canWin(available_stones, dp);
    }
    */
    /*
    bool canWin(int available_stones) {
        if (available_stones == 0) {
            return false;
        }
        for (int possible_stones = 1;
             possible_stones * possible_stones <= available_stones;
             possible_stones++) {
            // Check if opponent can win,
            // when current player takes possible_stones^2 stones
            if (canWin(available_stones - possible_stones * possible_stones) ==
                false) {
                // Current player wins
                return true;
            }
        }
        // Current player can't win
        return false;
    }
    bool winnerSquareGame(int n) {
        int available_stones = n;
        // Call for Alice
        return canWin(available_stones);
    }
    */
};