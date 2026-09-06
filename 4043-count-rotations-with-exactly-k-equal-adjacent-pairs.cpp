class Solution {
public:
    void leftShift(string& s, int n) {
        reverse(s.begin(), s.begin() + 1);
        reverse(s.begin() + 1, s.end());
        reverse(s.begin(), s.end());
    }
    int countRotations(string s, int k) {
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            leftShift(s, n);
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                if (s[i] == s[i - 1]) {
                    cnt++;
                }
            }
            if (cnt == k) {
                ans++;
            }
        }
        return ans;
    }
};