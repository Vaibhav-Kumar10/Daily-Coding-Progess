class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size(), ans = -1;
        unordered_map<int, int> freq;
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;
            // Add all k in that window
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }
            // Count in how many sub arrays those elements are preseny
            for (auto num : st) {
                freq[num]++;
            }
        }
        for (auto [num, f] : freq) {
            if (f == 1 && num > ans) {
                ans = num;
            }
        }
        return ans;
    }
};