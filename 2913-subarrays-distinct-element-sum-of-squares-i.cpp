class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> el_set;
            for (int j = i; j < n; j++) {
                el_set.insert(nums[j]);
                ans += (el_set.size() * el_set.size());
            }
        }
        return ans;
    }
};