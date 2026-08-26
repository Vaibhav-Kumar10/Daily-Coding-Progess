class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            if (a > 0) {
                st.push(a);
                continue;
            }
            while (!st.empty() && a < 0 && st.top() > 0 && st.top() < abs(a)) {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(a)) {
                st.pop();
            } else if (st.empty() || st.top() < 0) {
                st.push(a);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};