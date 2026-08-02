class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int cur_x = startPos[0], cur_y = startPos[1];
        int home_x = homePos[0], home_y = homePos[1];
        int n = rowCosts.size(), m = colCosts.size(), minCost = 0;
        // Go down
        if (cur_x <= home_x) {
            for (int r = cur_x + 1; r <= home_x; r++) {
                minCost = minCost + rowCosts[r];
            }
        }
        // Go up
        else {
            for (int r = cur_x - 1; r >= home_x; r--) {
                minCost = minCost + rowCosts[r];
            }
        }
        // Go right
        if (cur_y <= home_y) {
            for (int c = cur_y + 1; c <= home_y; c++) {
                minCost = minCost + colCosts[c];
            }
        }
        // Go left
        else {
            for (int c = cur_y - 1; c >= home_y; c--) {
                minCost = minCost + colCosts[c];
            }
        }
        return minCost;

        /*
        int n = rowCosts.size(), m = colCosts.size(), minCost = INT_MAX;
        queue<tuple<int, int, int>> q;
        q.push({cur_x, cur_y, 0});
        while (!q.empty()) {
            auto [x, y, cost] = q.front();
            q.pop();
            if (x == home_x && y == home_y) {
                minCost = min(minCost, cost);
                continue;
            }
            if (x + 1 < n && x + 1 <= home_x) {
                q.push({x + 1, y, cost + rowCosts[x + 1]});
            }
            if (x - 1 >= 0 && x - 1 >= home_x) {
                q.push({x - 1, y, cost + rowCosts[x - 1]});
            }
            if (y + 1 < m && y + 1 <= home_y) {
                q.push({x, y + 1, cost + colCosts[y + 1]});
            }
            if (y - 1 >= 0 && y - 1 >= home_y) {
                q.push({x, y - 1, cost + colCosts[y - 1]});
            }
        }
        return minCost;
        */
    }
};