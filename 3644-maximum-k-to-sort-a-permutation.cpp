class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        for (int i = 0; i < n; i++) {
            // not in correct position
            if (nums[i] != i) {
                ans = ans & nums[i];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};