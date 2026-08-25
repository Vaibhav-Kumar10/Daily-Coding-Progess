class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    bool isConnected(int a, int b) { return findParent(a) == findParent(b); }
    void union_by_size(int a, int b) {
        int par_a = findParent(a), par_b = findParent(b);
        if (par_a == par_b) {
            return;
        }
        if (size[par_a] >= size[par_b]) {
            size[par_a] += size[par_b];
            parent[par_b] = par_a;
        } else if (size[par_a] < size[par_b]) {
            size[par_b] += size[par_a];
            parent[par_a] = par_b;
        }
    }
};
class Solution {
public:
    int findMSTusingKruskal(int n,
                            vector<tuple<int, int, int, int>>& indexed_edges,
                            int removed_edge_index = -1,
                            int again_added_edge_index = -1) {
        DSU dsu(n);
        // Traverse through all the edges, and connect them if not connected,
        // ensuring no cycles form
        int MST_wt = 0, edges_used = 0;

        // Use that specified edge first
        if (again_added_edge_index != -1) {
            for (auto [wt, a, b, idx] : indexed_edges) {
                if (idx == again_added_edge_index) {
                    dsu.union_by_size(a, b);
                    MST_wt += wt;
                    edges_used++;
                    break;
                }
            }
        }

        for (auto edge : indexed_edges) {
            auto [wt, a, b, idx] = edge;
            if (idx == removed_edge_index || idx == again_added_edge_index) {
                continue;
            }
            if (!dsu.isConnected(a, b)) {
                dsu.union_by_size(a, b);
                MST_wt += wt;
                edges_used++;
            }
        }
        if (edges_used != n - 1) {
            return INT_MAX;
        }
        return MST_wt;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // 1. Store the edges along with their respective index
        // { weight, a, b, index }
        vector<tuple<int, int, int, int>> indexed_edges;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1], wt = edges[i][2];
            indexed_edges.push_back({wt, a, b, i});
        }

        sort(begin(indexed_edges), end(indexed_edges));
        // 2. Using Kruskal's Algorithm find MST
        // Sort acc. to weights
        int MST_wt = findMSTusingKruskal(n, indexed_edges);

        // 3. Check for each edge id it is Crtical or Pseudo Critical.
        vector<vector<int>> ans_edges = {{}, {}};

        for (auto edge : indexed_edges) {
            auto [wt, a, b, idx] = edge;
            // If after removing cur edge, MST_wt increases or impossible
            // => it must be present in all the possible MSTs
            // => It is a Critical edge

            // Remove current edge
            int MST_without_cur_edge =
                findMSTusingKruskal(n, indexed_edges, idx, -1);

            if (MST_without_cur_edge > MST_wt) {
                ans_edges[0].push_back(idx);
            }

            // If after again adding cur edge, MST_wt remains the same
            // => it can be present in some of the possible MSTs
            // => It is a Pseudo-Critical edge
            else {
                int MST_with_cur_edge =
                    findMSTusingKruskal(n, indexed_edges, -1, idx);
                if (MST_with_cur_edge == MST_wt) {
                    ans_edges[1].push_back(idx);
                }
            }
        }
        return ans_edges;
    }
};