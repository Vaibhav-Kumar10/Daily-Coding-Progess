class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size(), idx = -1, minDist = INT_MAX;
        int tx = target[0], ty = target[1];
        for (int i = 0; i < n; i++) {
            int x = drones[i][0], y = drones[i][1], range = drones[i][2];
            int dist = abs(x - tx) + abs(y - ty);
            if (dist <= range && dist < minDist) {
                minDist = dist;
                idx = i;
            }
        }
        return idx;
    }
};