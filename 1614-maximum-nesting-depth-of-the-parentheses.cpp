class Solution {
public:
    int maxDepth(string s) {
        int parenthesis = 0, maxDepth = 0;
        for (char ch : s) {
            if (ch == '(') {
                parenthesis++;
            } else if (ch == ')') {
                parenthesis--;
            }
            maxDepth = max(maxDepth, parenthesis);
        }
        return maxDepth;
    }
};