class Solution {
public:
    long long detCntUsingBFS(int src, vector<vector<int>>& adj, int n) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(src);
        visited[src] = true;
        long long cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        long long n = bombs.size(), maxDets = 0;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                long long x2 = bombs[j][0], y2 = bombs[j][1];

                long long dx = x1 - x2, dy = y1 - y2;
                long long distSq = dx * dx + dy * dy;

                // If that bomb affects that neighbour
                if (distSq <= r * r) {
                    adj[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            long long dets = detCntUsingBFS(i, adj, n);
            maxDets = max(maxDets, dets);
        }
        return maxDets;
    }
};