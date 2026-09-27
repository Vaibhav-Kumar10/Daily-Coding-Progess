class Solution {
public:
    int n, idx;
    string s;
    set<string> find_single() {
        set<string> ans;
        if (s[idx] == '{') {
            idx++;
            ans = do_union();
        } else {
            ans.insert(string(1, s[idx]));
        }
        idx++;
        return ans;
    }
    set<string> do_concat() {
        set<string> ans;
        while (idx < n && (s[idx] == '{' || isalpha(s[idx]))) {
            set<string> concat_res, temp = find_single();
            if (ans.empty()) {
                ans = temp;
            } else {
                for (string left : ans) {
                    for (string right : temp) {
                        concat_res.insert(left + right);
                    }
                }
                ans = concat_res;
            }
        }
        return ans;
    }
    set<string> do_union() {
        set<string> ans;
        while (true) {
            set<string> temp = do_concat();
            ans.insert(temp.begin(), temp.end());
            if (idx < n && s[idx] == ',') {
                idx++;
            } else {
                break;
            }
        }
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        n = expression.size();
        s = expression;
        idx = 0;
        set<string> st = do_union();
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};