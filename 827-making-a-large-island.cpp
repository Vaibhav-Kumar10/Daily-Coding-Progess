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
    bool connected(int u, int v) { return findParent(u) == findParent(v); }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxNodes = n * m, maxArea = 0;
        DSU dsu(maxNodes);
        vector<int> ans, dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        // Mark all the components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k], nc = j + dc[k];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                        grid[nr][nc] == 0) {
                        continue;
                    }
                    int nbr_node = nr * m + nc, node = i * m + j;
                    dsu.union_by_size(node, nbr_node);
                }
            }
        }
        // Try changing zeros one by one
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    continue;
                }
                // Get all the neighbouring components, connected to cur node
                unordered_set<int> components;
                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k], nc = j + dc[k];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                        grid[nr][nc] == 0) {
                        continue;
                    }
                    int nbr_node = nr * m + nc;
                    components.insert(dsu.findParent(nbr_node));
                }
                int area = 1;
                for (int component : components) {
                    area += dsu.size[component];
                }
                maxArea = max(maxArea, area);
            }
        }
        // Only ones => no 0 to flip
        for (int node = 0; node < maxNodes; node++) {
            maxArea = max(maxArea, dsu.size[node]);
        }
        return maxArea;
    }
};
/*
class Solution {
public:
    int bfs(int r, int c, vector<vector<int>>& grid,
            vector<vector<int>>& visited, int n, int m) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            cnt += grid[row][col];
            vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    grid[nr][nc] != 0 && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return cnt;
    }
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& visited, int n, int m) {
        int cnt = grid[row][col];
        visited[row][col] = 1;
        vector<int> dr = {-1, 0, 1, 0}, dc = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i], nc = col + dc[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] != 0 &&
                !visited[nr][nc]) {
                cnt += dfs(nr, nc, grid, visited, n, m);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxArea = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    int area = bfs(i, j, grid, visited, n, m);
                    // int totalValue = dfs(i, j, grid, visited, n, m);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = maxAreaOfIsland(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    ans = max(ans, maxAreaOfIsland(grid));
                    grid[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
*/