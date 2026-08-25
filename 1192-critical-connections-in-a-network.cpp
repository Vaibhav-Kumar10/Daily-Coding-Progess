class Solution {
public:
    int timer = 1;
    vector<vector<int>> crit_con;
    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<bool>& visited, vector<int>& first_time,
             vector<int>& lowest_time, int n) {
        visited[node] = true;
        first_time[node] = timer;
        lowest_time[node] = timer;
        timer++;
        for (auto nbr : adj[node]) {
            if (nbr == parent) {
                continue;
            } else if (!visited[nbr]) {
                dfs(nbr, node, adj, visited, first_time, lowest_time, n);
                lowest_time[node] = min(lowest_time[nbr], lowest_time[node]);
                if (lowest_time[nbr] > first_time[node]) {
                    // Can't reach the node from nbr
                    // => Bridge node => can't be removed
                    crit_con.push_back({node, nbr});
                }
            } else if (nbr != parent) {
                lowest_time[node] = min(lowest_time[nbr], lowest_time[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto conn : connections) {
            int a = conn[0], b = conn[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visited(n, false);
        vector<int> first_time(n), lowest_time(n);

        dfs(0, -1, adj, visited, first_time, lowest_time, n);

        return crit_con;
    }
};