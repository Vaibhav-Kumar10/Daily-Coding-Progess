class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        int l = 0, r = 0, n = nums.size(), sub_arr_cnt = 0;
        long long cur_prod = 1;
        for (r; r < n; r++) {
            cur_prod *= nums[r];
            while (l <= r && cur_prod >= k) {
                cur_prod /= nums[l];
                l++;
            }
            sub_arr_cnt += (r - l + 1);
        }
        return sub_arr_cnt;
    }
};