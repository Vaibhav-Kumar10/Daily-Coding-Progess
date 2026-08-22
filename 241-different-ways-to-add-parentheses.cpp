class Solution {
public:
    vector<int> f(string s) {
        vector<int> ans;
        int n = s.size();
        if (n == 0) {
            return ans;
        }
        if (n == 1) {
            ans.push_back(stoi(s));
            return ans;
        }
        if (n == 2 && isdigit(s[0])) {
            ans.push_back(stoi(s));
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left_ans = f(s.substr(0, i));
                vector<int> right_ans = f(s.substr(i + 1));
                for (int a : left_ans) {
                    for (int b : right_ans) {
                        if (s[i] == '+') {
                            ans.push_back(a + b);
                        } else if (s[i] == '-') {
                            ans.push_back(a - b);
                        } else if (s[i] == '*') {
                            ans.push_back(a * b);
                        }
                    }
                }
            }
        }
        // No operator found => it is a number
        if (ans.empty()) {
            ans.push_back(stoi(s));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) { return f(expression); }
};