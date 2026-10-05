class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char ch : s) {
            // a new pair starts
            if (ch == '(') {
                st.push(0);
            }
            // a pair has ended
            else if (ch == ')') {
                int nested = st.top();
                st.pop();
                int others = st.top();
                st.pop();
                // ()()
                if (nested == 0) {
                    st.push(others + 1);
                }
                // (A)
                else {
                    st.push(others + 2 * nested);
                }
            }
        }
        return st.top();
    }
};