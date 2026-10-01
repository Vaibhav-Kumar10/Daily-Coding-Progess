class Solution {
public:
    bool isValid(string s) {
        stack<char> charSet;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                charSet.push(ch);
            } else {
                // No opening parenthesis exists
                if (charSet.empty()) {
                    return false;
                }
                if (ch == ')' && charSet.top() == '(') {
                    charSet.pop();
                } else if (ch == ']' && charSet.top() == '[') {
                    charSet.pop();
                } else if (ch == '}' && charSet.top() == '{') {
                    charSet.pop();
                } else {
                    return false;
                }
            }
        }
        // If stack is empty => all parentheses are present in valid pairs
        return charSet.empty();
    }
};