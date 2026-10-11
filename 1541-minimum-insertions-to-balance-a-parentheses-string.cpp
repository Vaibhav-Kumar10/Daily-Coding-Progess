class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0, cnt = 0, n = s.length(), i = 0;
        while (i < n) {
            // Opening parentheses found
            if (s[i] == '(') {
                cnt++;
                i++;
            }
            // Closing parentheses found
            else {
                // balancing an opening parentheses
                if (cnt > 0) {
                    cnt--;
                }
                // opening parentheses required
                else {
                    insertions++;
                }
                // balanced
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                }
                // or not
                else {
                    i++;
                    insertions++;
                }
            }
        }
        if (cnt > 0) {
            insertions += cnt * 2;
        }
        return insertions;
    }
};