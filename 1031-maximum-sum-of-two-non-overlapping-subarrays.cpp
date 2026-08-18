class Solution {
public:
    int f(vector<int>& nums, vector<int>& prefixSum, int l_len, int r_len) {
        int n = nums.size(), ans = 0, maxLeftSubArrSum = 0;
        for (int r_end = l_len + r_len - 1; r_end < n; r_end++) {
            int l_end = r_end - r_len;
            int l_start_prev = l_end - l_len;
            int r_block_sum = prefixSum[r_end] - prefixSum[l_end];
            int l_block_sum = prefixSum[l_end] -
                              (l_start_prev < 0 ? 0 : prefixSum[l_start_prev]);
            maxLeftSubArrSum = max(maxLeftSubArrSum, l_block_sum);
            ans = max(ans, maxLeftSubArrSum + r_block_sum);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        int l_before_m = f(nums, prefixSum, firstLen, secondLen);
        int m_before_l = f(nums, prefixSum, secondLen, firstLen);
        return max(l_before_m, m_before_l);
    }
};