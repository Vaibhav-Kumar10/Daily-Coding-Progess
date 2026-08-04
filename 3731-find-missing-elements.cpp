class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minEl = nums[0], maxEl = nums[n - 1];
        set<int> st;
        for (int i = minEl; i <= maxEl; i++) {
            st.insert(i);
        }
        for (int num : nums) {
            st.erase(num);
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};