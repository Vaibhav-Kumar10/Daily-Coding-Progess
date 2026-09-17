class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    bool isConnected(int u, int v) { return findParent(u) == findParent(v); }
    void union_by_size(int u, int v) {
        int p_u = findParent(u), p_v = findParent(v);
        if (p_u == p_v) {
            return;
        }
        if (size[p_u] >= size[p_v]) {
            size[p_u] += size[p_v];
            parent[p_v] = p_u;
        } else if (size[p_u] < size[p_v]) {
            size[p_v] += size[p_u];
            parent[p_u] = p_v;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        DSU dsu(26);
        for (string eq : equations) {
            char a = eq[0], b = eq[3], op = eq[1];
            if (op == '=') {
                // if (!dsu.isConnected(a - 'a', b - 'a')) {
                dsu.union_by_size(a - 'a', b - 'a');
                // }
            }
        }
        for (string eq : equations) {
            char a = eq[0], b = eq[3], op = eq[1];
            if (op == '!') {
                if (dsu.isConnected(a - 'a', b - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};