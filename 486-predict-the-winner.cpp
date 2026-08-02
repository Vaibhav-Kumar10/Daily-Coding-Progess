class Solution {
public:
    int f(int left, int right, vector<int>& nums, int n,
          vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }
        if (left == right) {
            return nums[left];
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        // Player 1 take left
        int take_left = nums[left];
        int l_p2_score = f(left + 1, right, nums, n, dp);
        take_left -= l_p2_score;

        // Player 1 take right
        int take_right = nums[right];
        int r_p2_score = f(left, right - 1, nums, n, dp);
        take_right -= r_p2_score;

        return dp[left][right] = max(take_left, take_right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), total_score = 0;
        for (int stone : nums) {
            total_score += stone;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int score_dif = f(0, n - 1, nums, n, dp);
        return score_dif >= 0;
    }
    /*
    int f(int left, int right, vector<int>& nums, int n,
          vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        // Player 1 take left
        int take_left = nums[left];
        int l_p2_take_left = f(left + 2, right, nums, n, dp);
        int l_p2_take_right = f(left + 1, right - 1, nums, n, dp);
        take_left += min(l_p2_take_left, l_p2_take_right);

        // Player 1 take right
        int take_right = nums[right];
        int r_p2_take_left = f(left + 1, right - 1, nums, n, dp);
        int r_p2_take_right = f(left, right - 2, nums, n, dp);
        take_right += min(r_p2_take_left, r_p2_take_right);

        return dp[left][right] = max(take_left, take_right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), total_score = 0;
        for (int stone : nums) {
            total_score += stone;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int p1_score = f(0, n - 1, nums, n, dp);
        int p2_score = total_score - p1_score;
        return p1_score >= p2_score;
    }
    */
};