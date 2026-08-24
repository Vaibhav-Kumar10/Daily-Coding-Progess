class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        vector<int> reach_time(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        // { time , node }
        minHeap.push({0, k});
        reach_time[k] = 0;
        while (!minHeap.empty()) {
            auto [cur_time, node] = minHeap.top();
            minHeap.pop();
            if (cur_time > reach_time[node]) {
                continue;
            }
            for (auto [nbr, time] : adj[node]) {
                if (cur_time + time < reach_time[nbr]) {
                    reach_time[nbr] = cur_time + time;
                    minHeap.push({reach_time[nbr], nbr});
                }
            }
        }
        int min_reach_time = 0;
        for (int i = 1; i <= n; i++) {
            if (reach_time[i] == INT_MAX) {
                // At least one node is unreachable
                return -1;
            }
            min_reach_time = max(min_reach_time, reach_time[i]);
        }
        return min_reach_time;
    }
};
