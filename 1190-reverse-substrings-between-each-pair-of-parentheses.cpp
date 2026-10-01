class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        // store the counter brackets
        unordered_map<int, int> counter_bracket;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int rev_bracket = st.top();
                st.pop();
                counter_bracket[i] = rev_bracket;
                counter_bracket[rev_bracket] = i;
            }
        }
        string ans = "";
        int i = 0, delta = 1;
        while (i < n) {
            // switch the direction od traversal
            // whenever a bracket is encountered
            if (s[i] == '(' || s[i] == ')') {
                i = counter_bracket[i];
                delta = -1 * delta;
            }
            // add the character to ans 
            else {
                ans += s[i];
            }
            i += delta;
        }
        return ans;
    }
    /*
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
    */
};