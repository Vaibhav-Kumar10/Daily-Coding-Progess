class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        queue<pair<int, vector<int>>> q;
        vector<int> path;
        path.push_back(0);
        q.push({0, path});
        while (!q.empty()) {
            auto [node, cur_path] = q.front();
            q.pop();
            if (node == n - 1) {
                paths.push_back(cur_path);
                continue;
            }
            for (auto nbr : graph[node]) {
                cur_path.push_back(nbr);
                q.push({nbr, cur_path});
                cur_path.pop_back();
            }
        }
        return paths;
    }
};