class Solution {
public:
    int maxLen = 0;
    void f(int ind, string& cur, int cnt, string& s, int n,
           set<string>& ans_set) {
        if (cnt < 0) {
            return;
        }
        if (ind == n) {
            // if balanced
            if (cnt == 0) {
                if (cur.size() > maxLen) {
                    ans_set.clear();
                    ans_set.insert(cur);
                    maxLen = cur.size();
                } else if (cur.size() == maxLen) {
                    ans_set.insert(cur);
                    maxLen = cur.size();
                }
            }
            return;
        }
        if (s[ind] != '(' && s[ind] != ')') {
            cur.push_back(s[ind]);
            f(ind + 1, cur, cnt, s, n, ans_set);
            cur.pop_back();
            return;
        }
        // take cur ch
        int new_cnt = cnt;
        if (s[ind] == ')') {
            new_cnt--;
        } else if (s[ind] == '(') {
            new_cnt++;
        }
        cur.push_back(s[ind]);
        f(ind + 1, cur, new_cnt, s, n, ans_set);
        cur.pop_back();

        // skip cur ch
        f(ind + 1, cur, cnt, s, n, ans_set);
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), ind = 0, cnt = 0;
        string cur = "";
        set<string> ans_set;
        f(ind, cur, cnt, s, n, ans_set);
        return vector<string>(ans_set.begin(), ans_set.end());
    }
    /*
    void f(int ind, string cur, int cnt, string& s, int n,
           vector<set<string>>& ans_set) {
        if (cnt < 0) {
            return;
        }
        if (ind == n) {
            if (cnt == 0) {
                ans_set[cur.size()].insert(cur);
            }
            return;
        }
        // take cur ch
        int new_cnt = cnt;
        if (s[ind] == ')') {
            new_cnt--;
        } else if (s[ind] == '(') {
            new_cnt++;
        }
        f(ind + 1, cur + s[ind], new_cnt, s, n, ans_set);
        // skip cur ch
        f(ind + 1, cur, cnt, s, n, ans_set);
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), ind = 0, cnt = 0;
        string cur = "";
        vector<set<string>> ans_set(n + 1);
        vector<string> ans;
        f(ind, cur, cnt, s, n, ans_set);
        for (int i = n; i >= 0; i--) {
            if (ans_set[i].empty()) {
                continue;
            }
            return vector<string>(ans_set[i].begin(), ans_set[i].end());
        }
        return ans;
    }
    */
};