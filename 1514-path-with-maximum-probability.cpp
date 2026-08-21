class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            double pathProb = succProb[i];
            adj[a].push_back({pathProb, b});
            adj[b].push_back({pathProb, a});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        pq.push({maxProb[start_node], start_node});
        while (!pq.empty()) {
            auto [curProb, node] = pq.top();
            pq.pop();
            if (curProb < maxProb[node]) {
                continue;
            }
            if (node == end_node) {
                return curProb;
            }
            for (auto [nbrProb, nbr] : adj[node]) {
                if (curProb * nbrProb > maxProb[nbr]) {
                    maxProb[nbr] = curProb * nbrProb;
                    pq.push({maxProb[nbr], nbr});
                }
            }
        }
        return 0.0;
    }
};