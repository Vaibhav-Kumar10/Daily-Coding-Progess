class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> components(n, 0);
        for (int i = 1; i < n; i++) {
            int dif = nums[i] - nums[i - 1];
            components[i] = components[i - 1];
            if (dif > maxDiff) {
                components[i]++;
            }
        }
        vector<bool> ans;
        for (auto query : queries) {
            int u = query[0], v = query[1];
            ans.push_back(components[u] == components[v]);
        }
        return ans;
    }
};