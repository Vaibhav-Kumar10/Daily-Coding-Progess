class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size(), seqSum = nums[0], i = 1;
        for (i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                seqSum += nums[i];
            } else {
                break;
            }
        }
        unordered_set<int> st(nums.begin(), nums.end());
        while (st.find(seqSum) != st.end()) {
            seqSum++;
        }
        return seqSum;
    }
};