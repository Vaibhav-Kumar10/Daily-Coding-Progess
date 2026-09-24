class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> prevOccIdx;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x, n = nums.size(), maxLen = -1, cur_sum = 0;
        prevOccIdx[0] = -1;
        if (target == 0) {
            return n;
        }
        for (int i = 0; i < n; i++) {
            cur_sum += nums[i];
            int req = cur_sum - target;
            if (prevOccIdx.find(req) != prevOccIdx.end()) {
                maxLen = max(maxLen, i - prevOccIdx[req]);
            }
            if (prevOccIdx.find(cur_sum) == prevOccIdx.end()) {
                prevOccIdx[cur_sum] = i;
            }
        }
        if (maxLen == -1) {
            return -1;
        }
        return n - maxLen;
    }
};