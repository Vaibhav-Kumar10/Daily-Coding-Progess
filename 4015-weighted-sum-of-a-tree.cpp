class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        int height = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                auto node = q.front();
                q.pop();
                for (int child : adj[node]) {
                    q.push(child);
                }
            }
            height++;
        }
        queue<pair<int, int>> q2;
        q2.push({0, 1});
        long long ans = 0;
        while (!q2.empty()) {
            auto [node, level] = q2.front();
            q2.pop();
            ans = ans + nums[node] * 1LL * (height - level + 1);
            for (int child : adj[node]) {
                q2.push({child, level + 1});
            }
        }
        return ans;
    }
};