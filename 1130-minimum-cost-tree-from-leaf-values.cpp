class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxBw;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            maxBw[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxBw[{i, j}] = max(arr[j], maxBw[{i, j - 1}]);
            }
        }
        int left = 0, right = n - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int left = n - 1; left >= 0; left--) {
            for (int right = left + 1; right < n; right++) {
                if (left == right) {
                    continue;
                }
                int ans = INT_MAX;
                for (int i = left; i < right; i++) {
                    int maxLeafProd = maxBw[{left, i}] * maxBw[{i + 1, right}];
                    int rst = dp[i + 1][right];
                    int lst = dp[left][i];
                    ans = min(ans, maxLeafProd + lst + rst);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n - 1];
    }
    /*
    int f(int left, int right, vector<int>& arr,
          map<pair<int, int>, int>& maxBw, vector<vector<int>>& dp) {
        if (left == right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int ans = INT_MAX;
        for (int i = left; i < right; i++) {
            int maxLeafProd = maxBw[{left, i}] * maxBw[{i + 1, right}];
            int rst = f(i + 1, right, arr, maxBw, dp);
            int lst = f(left, i, arr, maxBw, dp);
            ans = min(ans, maxLeafProd + lst + rst);
        }
        return dp[left][right] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxBw;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            maxBw[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxBw[{i, j}] = max(arr[j], maxBw[{i, j - 1}]);
            }
        }
        int left = 0, right = n - 1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(left, right, arr, maxBw, dp);
    }
    */
};