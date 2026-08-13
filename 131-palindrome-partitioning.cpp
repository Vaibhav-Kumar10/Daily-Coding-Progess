class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void f(int ind, string& s, vector<string> cur,
           vector<vector<string>>& ans) {
        if (ind == s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                cur.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, s, cur, ans);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> ans;
        f(0, s, cur, ans);
        return ans;
    }
};