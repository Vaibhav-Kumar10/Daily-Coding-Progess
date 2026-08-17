class Solution {
public:
    int dp[502][502];
    int f(int left, int right, int total_sum, vector<int>& stoneValue) {
        if (left == right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int cur_sum = 0, ans = 0;
        for (int i = left; i < right; i++) {
            cur_sum += stoneValue[i];
            int rem_sum = total_sum - cur_sum;
            if (cur_sum > rem_sum) {
                ans = max(ans, rem_sum + f(i + 1, right, rem_sum, stoneValue));
            } else if (cur_sum < rem_sum) {
                ans = max(ans, cur_sum + f(left, i, cur_sum, stoneValue));
            } else {
                ans = max(ans, rem_sum + f(i + 1, right, rem_sum, stoneValue));
                ans = max(ans, cur_sum + f(left, i, cur_sum, stoneValue));
            }
        }
        return dp[left][right] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int total_sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        int right = stoneValue.size() - 1, left = 0;
        memset(dp, -1, sizeof(dp));
        return f(left, right, total_sum, stoneValue);
    }
};