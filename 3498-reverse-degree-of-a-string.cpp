class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            ans += (26 - s[i] + 'a') * (i + 1);
        }
        return ans;
    }
};