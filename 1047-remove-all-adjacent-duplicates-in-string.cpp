class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (char ch : s) {
            if (!ans.empty() && ans.back() == ch) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
    /*
    string removeDuplicates(string s) {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(i);
            } else if (s[st.top()] == s[i]) {
                st.pop();
            } else {
                st.push(i);
            }
        }
        string ans;
        while (!st.empty()) {
            ans += s[st.top()];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    */
};