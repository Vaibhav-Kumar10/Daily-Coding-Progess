class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, r = 0, n = nums.size(), maxLen = 0, culprit = 0;
        while (r < n) {
            freq[nums[r]]++;
            if (freq[nums[r]] == k + 1) {
                culprit++;
            }
            if (culprit > 0) {
                freq[nums[l]]--;
                if (freq[nums[l]] == k) {
                    culprit--;
                }
                l++;
            }
            if (culprit == 0) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
    /*
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), maxLen = 0;
        unordered_map<int, int> freq;
        while (r < n) {
            freq[nums[r]]++;
            while (l < r && freq[nums[r]] > k) {
                freq[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
    */
};