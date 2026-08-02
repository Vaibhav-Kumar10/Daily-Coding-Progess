class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size(), valid = 0;
        // double a_b = 1.0 * a / b;
        for (int l = 0; l < n; l++) {
            int even_cnt = 0, odd_cnt = 0;
            // if (nums[l] % 2 == 0) {
            //     even_cnt++;
            // } else {
            //     odd_cnt++;
            // }
            for (int r = l; r < n; r++) {
                if (nums[r] % 2 == 0) {
                    even_cnt++;
                } else {
                    odd_cnt++;
                }
                if (odd_cnt > 0) {
                    // double even_by_odd = 1.0 * even_cnt / odd_cnt;
                    long long mul1 = even_cnt * b * 1LL;
                    long long mul2 = odd_cnt * a * 1LL;
                    if (mul1 <= mul2) {
                        valid++;
                    }
                }
            }
        }
        return valid;
    }
};