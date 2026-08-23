class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == destination) {
                return true;
            }
            for (auto nbr : adj[node]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        return false;
    }
};