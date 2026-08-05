class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<bool> suspicious(n, false);
        vector<int> indegree(n, 0);
        for (auto edge : invocations) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto nbr : adj[node]) {
                indegree[nbr]--;
                if (!suspicious[nbr]) {
                    q.push(nbr);
                    suspicious[nbr] = true;
                }
            }
        }
        bool noChange = false;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] && indegree[i] != 0) {
                noChange = true;
                break;
            }
        }
        if (noChange) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!suspicious[i]) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};