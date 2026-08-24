class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto route : flights) {
            int from = route[0], to = route[1], price = route[2];
            adj[from].push_back({to, price});
        }
        // { stops, city, cost }
        queue<tuple<int, int, int>> q;
        vector<int> costs(n, INT_MAX);
        q.push({0, src, 0});
        costs[src] = 0;
        while (!q.empty()) {
            auto [stops, city, cost] = q.front();
            q.pop();
            if (stops > k) {
                continue;
            }

            for (auto [nbr, nbr_cost] : adj[city]) {
                if (cost + nbr_cost < costs[nbr] && stops <= k) {
                    costs[nbr] = cost + nbr_cost;
                    q.push({stops + 1, nbr, costs[nbr]});
                }
            }
        }
        return costs[dst] == INT_MAX ? -1 : costs[dst];
    }
};
