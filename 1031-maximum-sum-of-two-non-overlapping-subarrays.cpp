class Solution {
public:
    int f(vector<int>& nums, int l_len, int r_len) {
        int n = nums.size(), r_block_sum = 0, l_block_sum = 0;
        // Left block: [0, l_len - 1]
        for (int i = 0; i < l_len; i++) {
            l_block_sum += nums[i];
        }
        // Right block: [l_len, l_len + r_len - 1]
        for (int i = l_len; i < l_len + r_len; i++) {
            r_block_sum += nums[i];
        }
        int ans = l_block_sum + r_block_sum, maxLeftSubArrSum = l_block_sum;

        for (int r_end = l_len + r_len; r_end < n; r_end++) {
            int l_end = r_end - r_len;
            int l_start_prev = l_end - l_len;

            // Left block moves one position right
            l_block_sum += nums[l_end] - nums[l_start_prev];

            // Right block moves one position right
            r_block_sum += nums[r_end] - nums[r_end - r_len];

            maxLeftSubArrSum = max(maxLeftSubArrSum, l_block_sum);
            ans = max(ans, maxLeftSubArrSum + r_block_sum);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int l_before_m = f(nums, firstLen, secondLen);
        int m_before_l = f(nums, secondLen, firstLen);
        return max(l_before_m, m_before_l);
    }
    /*
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
    */
};