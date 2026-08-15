class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cur_xor = 0, n = nums.size(), zero_cnt = 0;
        for (int num : nums) {
            if (num == 0) {
                zero_cnt++;
            }
            cur_xor ^= num;
        }
        if (cur_xor != 0) {
            return n;
        }
        if (zero_cnt == n) {
            return 0;
        }
        return n - 1;
    }
};