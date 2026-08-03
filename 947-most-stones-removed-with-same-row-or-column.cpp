class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int a) {
        if (a == parent[a]) {
            return a;
        }
        return parent[a] = findParent(parent[a]);
    }
    void union_by_size(int a, int b) {
        int par_a = findParent(a), par_b = findParent(b);
        if (par_a == par_b) {
            return;
        }
        if (size[par_a] >= size[par_b]) {
            parent[par_b] = par_a;
            size[par_a] += size[par_b];
        } else {
            parent[par_a] = par_b;
            size[par_b] += size[par_a];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), maxRow = 0, maxCol = 0, components = 0;
        for (int i = 0; i < n; i++) {
            int row = stones[i][0], col = stones[i][1];
            maxRow = max(maxRow, row);
            maxCol = max(maxCol, col);
        }
        DSU dsu(maxRow + maxCol + 2);
        unordered_set<int> rows_taken;
        for (int i = 0; i < n; i++) {
            int row = stones[i][0], col = stones[i][1];
            int col_as_row = col + maxRow + 1;
            dsu.union_by_size(row, col_as_row);
            rows_taken.insert(row);
            rows_taken.insert(col_as_row);
        }
        for (int row_node : rows_taken) {
            if (dsu.findParent(row_node) == row_node) {
                components++;
            }
        }
        return n - components;
    }
};