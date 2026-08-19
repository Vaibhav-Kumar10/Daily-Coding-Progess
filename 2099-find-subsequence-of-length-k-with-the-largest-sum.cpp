class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({i, nums[i]});
        }
        // sort by numerical value in descending order
        sort(arr.begin(), arr.end(),
             [&](const auto& a, const auto& b) { return a[1] > b[1]; });

        // select the first k elements and sort them in ascending order by index
        sort(arr.begin(), arr.begin() + k);

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i][1]);
        }
        return ans;
    }
};