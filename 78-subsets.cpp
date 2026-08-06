class Solution {
public:
    void f(int ind, vector<int>& cur, vector<vector<int>>& ans,
           vector<int>& nums, int n) {
        if (ind == n) {
            ans.push_back(cur);
            return;
        }
        // take cur num
        cur.push_back(nums[ind]);
        f(ind + 1, cur, ans, nums, n);
        cur.pop_back();
        // skip cur num
        f(ind + 1, cur, ans, nums, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        int n = nums.size();
        f(0, cur, ans, nums, n);
        return ans;
    }
};