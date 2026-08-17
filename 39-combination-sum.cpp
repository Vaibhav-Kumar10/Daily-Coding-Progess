class Solution {
public:
    void f(int ind, int target, vector<int>& arr, vector<int>& cur,
           vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (target < 0 || ind == arr.size()) {
            return;
        }
        // Take
        cur.push_back(arr[ind]);
        f(ind, target - arr[ind], arr, cur, ans);
        cur.pop_back();
        // Skip
        f(ind + 1, target, arr, cur, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = candidates.size();
        f(0, target, candidates, cur, ans);
        return ans;
    }
};