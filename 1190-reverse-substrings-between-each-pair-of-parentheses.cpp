class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        for (char ch : s) {
            if (ch == '(') {
                st.push(ans.length());
            } else if (ch == ')') {
                int idx = st.top();
                st.pop();
                reverse(ans.begin() + idx, ans.end());
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};