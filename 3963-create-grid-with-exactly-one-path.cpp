class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initially block all
        string s(n, '#');
        vector<string> ans(m, s);

        // Mark last column
        for (int r_v = 0; r_v < m; r_v++) {
            ans[r_v][n - 1] = '.';
        }

        // Mark first row
        for (int c_v = 0; c_v < n; c_v++) {
            ans[0][c_v] = '.';
        }

        return ans;
    }
};