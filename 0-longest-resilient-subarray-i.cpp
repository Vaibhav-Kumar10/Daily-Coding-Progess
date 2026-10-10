class Solution {
public:
    int resilientSubarray(vector<int>& nums, int K) {
        int n = nums.size(), maxLen = 1;
        if (n == 1) {
            return maxLen;
        }
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            int target_rem = nums[i] % K;
            for (int j = i; j < n; j++) {
                if ((nums[j] % K) != target_rem) {
                    break;
                }
                int sub_arr_sum = prefixSum[j + 1] - prefixSum[i];
                if ((sub_arr_sum % K) == target_rem) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};