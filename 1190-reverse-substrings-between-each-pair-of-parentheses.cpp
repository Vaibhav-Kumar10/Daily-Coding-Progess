class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        for (char ch : s) {
            // push the length of the string,
            // that we need to skip when reversing
            if (ch == '(') {
                st.push(ans.size());
            } else if (ch == ')') {
                int skip_length = st.top();
                st.pop();
                reverse(ans.begin() + skip_length, ans.end());
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};