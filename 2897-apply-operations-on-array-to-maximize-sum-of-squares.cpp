class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> set_bit_cnt(32, 0);
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1 << bit)) {
                    set_bit_cnt[bit]++;
                }
            }
        }
        long long ans = 0, MOD = 1e9 + 7;
        while (k--) {
            long long cur = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (set_bit_cnt[bit] > 0) {
                    set_bit_cnt[bit]--;
                    cur = cur | (1 << bit);
                }
            }
            ans = (ans + (cur * cur)) % MOD;
        }
        return ans;
    }
};