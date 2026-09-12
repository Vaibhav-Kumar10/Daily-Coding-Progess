class Solution {
public:
    vector<int> dp;
    int f(int day, int target) {
        if (target == 0) {
            return 0;
        }
        if (dp[target] != -1) {
            return dp[target];
        }
        int min_days_req = 1e9;
        // max score by a streak of s day => s * (s + 1 ) / 2
        for (int streak = 1; ((streak * (streak + 1)) / 2) <= target;
             streak++) {
            int cur_score = (streak * (streak + 1)) / 2;
            // maintain a streak of streak days
            if (cur_score == target) {
                min_days_req = min(min_days_req, streak);
            }
            // take reset streak after streak days
            else {
                int skip_after_streak =
                    streak + 1 + f(day + streak + 1, target - cur_score);
                min_days_req = min(min_days_req, skip_after_streak);
            }
        }
        return dp[target] = min_days_req;
    }
    int minDays(int n) {
        // s day streak => 1 + 2 + 3 + ... s = sum(s natural numbers)
        // => s * (s + 1 ) / 2
        // n => 1e5 at max
        // => s * (s + 1 ) / 2 <= 1e5
        // s ~~ sqrt(2 * 1e5)
        // => 500 at max bcz 500 * 500 = 25 * 1e4
        int day = 1;
        dp.resize(n + 1, -1);
        return f(day, n);
    }
    /*
    vector<vector<int>> dp;
    int f(int day, int cur_streak, int target) {
        if (target == 0) {
            return 0;
        }
        if (dp[cur_streak][target] != -1) {
            return dp[cur_streak][target];
        }
        // take
        int next_streak = cur_streak + 1;
        int take = next_streak <= target
                       ? 1 + f(day + 1, next_streak, target - next_streak)
                       : 1e9;
        // skip
        int skip = cur_streak > 0 ? 1 + f(day + 1, 0, target) : 1e9;
        return dp[cur_streak][target] = min(take, skip);
    }
    int minDays(int n) {
        int day = 1, cur = 0;
        // s day streak => 1 +  2 + 3 + ... s = sum(s natural numbers)
        // => s * (s + 1 ) / 2
        // n => 1e5 at max
        // => s * (s + 1 ) / 2 <= 1e5
        // s ~~ sqrt(2 * 1e5)
        // => 500 at max bcz 500 * 500 = 25 * 1e4
        dp.resize(500, vector<int>(n + 1, -1));
        return f(day, cur, n);
    }
    */
};