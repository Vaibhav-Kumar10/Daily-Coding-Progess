class Solution {
public:
    // int stoneGameV(vector<int>& stoneValue) {
    //     int n = stoneValue.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    //     for (int left = n - 1; left >= 0; left--) {
    //         int total_sum = stoneValue[left];
    //         for (int right = left + 1; right < n; right++) {
    //             if (left == right) {
    //                 continue;
    //             }
    //             total_sum += stoneValue[right];
    //             int cur_sum = 0, ans = 0;
    //             for (int i = left; i < right; i++) {
    //                 cur_sum += stoneValue[i];
    //                 int rem_sum = total_sum - cur_sum;
    //                 if (cur_sum > rem_sum) {
    //                     ans = max(ans, rem_sum + dp[i + 1][right]);
    //                 } else if (cur_sum < rem_sum) {
    //                     ans = max(ans, cur_sum + dp[left][i]);
    //                 } else {
    //                     ans = max(ans, rem_sum + dp[i + 1][right]);
    //                     ans = max(ans, cur_sum + dp[left][i]);
    //                 }
    //             }
    //             dp[left][right] = ans;
    //         }
    //     }
    //     return dp[0][n - 1];
    // }
    // /*
    int dp[502][502];

    int f(int left, int right, int total_sum, vector<int>& stoneValue) {
        // Only one stone is left.
        // We cannot split it anymore.
        if (left == right) {
            return 0;
        }

        // Already calculated this interval.
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int cur_sum = 0;
        int ans = 0;

        // Try every possible split:
        //
        // [left ... i] | [i+1 ... right]
        //
        for (int i = left; i < right; i++) {

            // Sum of the left part.
            cur_sum += stoneValue[i];

            // Sum of the right part.
            int rem_sum = total_sum - cur_sum;

            // Left side is smaller.
            // Bob throws away the right side.
            // Alice keeps the left side.
            if (cur_sum > rem_sum) {

                ans = max(
                    ans,
                    rem_sum + f(i + 1, right, rem_sum, stoneValue)
                );

            }
            // Right side is smaller.
            // Bob throws away the left side.
            // Alice keeps the right side.
            else if (cur_sum < rem_sum) {

                ans = max(
                    ans,
                    cur_sum + f(left, i, cur_sum, stoneValue)
                );

            }
            // Both sides have equal sums.
            // Alice can choose either side.
            else {

                // Keep the right side.
                ans = max(
                    ans,
                    rem_sum + f(i + 1, right, rem_sum, stoneValue)
                );

                // Keep the left side.
                ans = max(
                    ans,
                    cur_sum + f(left, i, cur_sum, stoneValue)
                );
            }
        }

        return dp[left][right] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int total_sum =
            accumulate(stoneValue.begin(), stoneValue.end(), 0);

        int left = 0;
        int right = stoneValue.size() - 1;

        // Initialize every DP state to -1.
        memset(dp, -1, sizeof(dp));

        return f(left, right, total_sum, stoneValue);
    }
    // */
};