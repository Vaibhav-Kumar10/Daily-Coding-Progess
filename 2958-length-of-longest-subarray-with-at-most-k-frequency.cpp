class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), maxLen = 0;
        unordered_map<int, int> freq;
        while (r < n) {
            freq[nums[r]]++;
            while (freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};