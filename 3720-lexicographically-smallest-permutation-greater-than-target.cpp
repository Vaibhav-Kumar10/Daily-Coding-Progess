class Solution {
public:
    int freq[26];
    string ans;
    bool f(int ind, string& cur, string& s, string& target, int n,
           bool greater) {
        if (ind == n) {
            if (greater) {
                ans = cur;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0) {
                continue;
            }
            if (!greater && ch < target[ind]) {
                continue;
            }
            cur += ch;
            freq[ch - 'a']--;
            bool isGreater = greater || cur > target;
            if (f(ind + 1, cur, s, target, n, isGreater) == true) {
                return true;
            }
            cur.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        for (char ch : s) {
            freq[ch - 'a']++;
            cout << freq[ch - 'a'];
        }
        ans = "";
        bool greater = 0;
        int n = s.size(), ind = 0;
        string cur = "";
        f(ind, cur, s, target, n, greater);
        return ans;
    }
};