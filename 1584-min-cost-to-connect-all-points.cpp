class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int parU = findPar(u), parV = findPar(v);
        if (parU == parV) {
            return;
        }
        if (size[parU] <= size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        } else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
    bool isConnected(int u, int v) { return findPar(u) == findPar(v); }
};
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
    int MST_Using_Kruskal(vector<vector<int>>& edges, int n) {
        vector<tuple<int, int, int>> adj;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj.push_back({w, u, v});
        }
        int mst = 0;
        sort(adj.begin(), adj.end());
        DSU dsu = DSU(n);
        for (auto& [wt, node, nbr] : adj) {
            if (!dsu.isConnected(node, nbr)) {
                mst += wt;
                dsu.unionBySize(node, nbr);
            }
        }
        return mst;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        /*
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
        */
        vector<vector<int>> adj;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj.push_back({i, j, dist});
            }
        }
        int mst = MST_Using_Kruskal(adj, n);
        return mst;
    }
};