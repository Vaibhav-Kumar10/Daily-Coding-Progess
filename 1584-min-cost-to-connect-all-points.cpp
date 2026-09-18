class Solution {
public:
    int MST_Using_Prims(vector<vector<pair<int, int>>>& adj, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<bool> visited(n, false);
        int mst = 0;
        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (visited[node] == true) {
                continue;
            }
            visited[node] = true;
            mst += cost;
            for (auto [nbr, nbr_cost] : adj[node]) {
                if (!visited[nbr]) {
                    pq.push({nbr_cost, nbr});
                }
            }
        }
        return mst;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        int mst = MST_Using_Prims(adj, n);
        return mst;
    }
};