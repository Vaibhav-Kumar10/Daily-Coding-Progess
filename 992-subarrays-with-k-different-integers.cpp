class Solution {
public:
    int cntSubarrWithDistinctLTEk(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), cnt_sub_arrays = 0;
        unordered_map<int, int> freq;
        for (r; r < n; r++) {
            freq[nums[r]]++;
            while (l <= r && freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }
            cnt_sub_arrays += (r - l + 1);
        }
        return cnt_sub_arrays;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // No. of sub arrays with distinct <= k
        // -
        // No. of sub arrays with distinct <= k-1
        // =
        // No. of sub arrays with distinct == k
        return cntSubarrWithDistinctLTEk(nums, k) -
               cntSubarrWithDistinctLTEk(nums, k - 1);
    }
};