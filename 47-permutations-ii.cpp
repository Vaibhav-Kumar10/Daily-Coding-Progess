class Solution {
public:
    set<vector<int>> ans;
    void f(int ind, vector<int>& nums, int n) {
        if (ind == n) {
            ans.insert(nums);
            return;
        }
        for (int i = ind; i < n; i++) {
            swap(nums[i], nums[ind]);
            f(ind + 1, nums, n);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size(), ind = 0;
        f(ind, nums, n);
        vector<vector<int>> unique_ans(begin(ans), end(ans));
        sort(unique_ans.begin(), unique_ans.end());
        return unique_ans;
    }
};