class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
            } else if (ch == ')') {
                if (st.empty()) {
                    st.push(ch);
                } else if (st.top() == '(') {
                    st.pop();
                } else if (st.top() == ')') {
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};