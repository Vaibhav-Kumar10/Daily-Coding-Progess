class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        vector<int> ans;
        int n = nums.size();
        /*
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        */
        int lower_index =
            lower_bound(begin(nums), end(nums), target) - begin(nums);
        int upper_index =
            upper_bound(begin(nums), end(nums), target) - begin(nums);

        for (int i = lower_index; i < upper_index; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};