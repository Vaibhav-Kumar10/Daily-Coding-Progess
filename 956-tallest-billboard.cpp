class Solution {
public:
    vector<vector<int>> dp;
    int f(int ind, int dif, vector<int>& rods, int n) {
        if (ind == n) {
            return dif == 0 ? 0 : INT_MIN;
        }
        // 5000 => offset for -ve dif
        if (dp[ind][dif + 5000] != -1) {
            return dp[ind][dif + 5000];
        }
        // take in len1
        int take1 = rods[ind] + f(ind + 1, dif + rods[ind], rods, n);
        // take in len2
        int take2 = rods[ind] + f(ind + 1, dif - rods[ind], rods, n);
        // not take
        int not_take = f(ind + 1, dif, rods, n);
        return dp[ind][dif + 5000] = max({take1, take2, not_take});
    }
    int tallestBillboard(vector<int>& rods) {
        dp.assign(21, vector<int>(10002, -1));
        int n = rods.size();
        return f(0, 0, rods, n) / 2;
    }
    /*
    int f(int ind, int dif, vector<int>& rods, int n) {
        if (ind == n) {
            return dif == 0 ? 0 : INT_MIN;
        }
        // take in len1
        int take1 = rods[ind] + f(ind + 1, dif + rods[ind], rods, n);
        // take in len2
        int take2 = rods[ind] + f(ind + 1, dif - rods[ind], rods, n);
        // not take
        int not_take = f(ind + 1, dif, rods, n);
        return max({take1, take2, not_take});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        return f(0, 0, rods, n) / 2;
    }
    */
    /*
    int f(int ind, int len1, int len2, vector<int>& rods, int n) {
        if (ind == n) {
            return len1 == len2 ? len1 : 0;
        }
        // take in len1
        int take1 = f(ind + 1, len1 + rods[ind], len2, rods, n);
        // take in len2
        int take2 = f(ind + 1, len1, len2 + rods[ind], rods, n);
        // not take
        int not_take = f(ind + 1, len1, len2, rods, n);
        return max({take1, take2, not_take});
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), len1 = 0, len2 = 0;
        return f(0, len1, len2, rods, n);
    }
    */
};