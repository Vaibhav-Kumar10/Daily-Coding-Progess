class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int outer = 0;
        for (char ch : s) {
            if (ch == '(') {
                // if the outer parenthesis is considered
                if (outer > 0) {
                    ans += ch;
                }
                outer++;
            } else if (ch == ')') {
                outer--;
                // if the outer parenthesis is considered
                if (outer > 0) {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};