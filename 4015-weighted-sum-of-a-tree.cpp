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
        vector<int> levels(n, 0);
        q.push(0);
        levels[0] = 1;
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                auto node = q.front();
                q.pop();
                for (int child : adj[node]) {
                    q.push(child);
                    levels[child] = levels[node] + 1;
                }
            }
            height++;
        }
        long long ans = 0;
        for (int node = 0; node < n; node++) {
            ans = ans + nums[node] * 1LL * (height - levels[node] + 1);
        }
        return ans;
    }
};