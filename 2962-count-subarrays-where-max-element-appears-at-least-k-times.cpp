class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), maxEl = INT_MIN;
        for (int el : nums) {
            maxEl = max(maxEl, el);
        }
        long long maxEl_cnt = 0, sub_arr_cnt = 0;
        while (r < n) {
            if (nums[r] == maxEl) {
                maxEl_cnt++;
            }
            while (maxEl_cnt >= k) {
                sub_arr_cnt += (n - r);
                if (nums[l] == maxEl) {
                    maxEl_cnt--;
                }
                l++;
            }
            r++;
        }
        return sub_arr_cnt;
    }
};