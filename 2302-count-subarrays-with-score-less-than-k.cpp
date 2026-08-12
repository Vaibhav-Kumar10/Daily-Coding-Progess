class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0, r = 0, n = nums.size();
        long long sub_arr_cnt = 0, cur_sum = 0;
        for (r; r < n; r++) {
            cur_sum += nums[r];
            long long score = cur_sum * (r - l + 1);
            while (score >= k) {
                cur_sum -= nums[l];
                l++;
                score = cur_sum * (r - l + 1);
            }
            sub_arr_cnt += (r - l + 1);
        }
        return sub_arr_cnt;
    }
};