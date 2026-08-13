class Solution {
public:
    void f(string cur, vector<string>& ans, int n, int leftCnt, int rightCnt) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (leftCnt < n) {
            f(cur + '(', ans, n, leftCnt + 1, rightCnt);
        }
        if (rightCnt < leftCnt) {
            f(cur + ')', ans, n, leftCnt, rightCnt + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        int leftCnt = 0, rightCnt = 0;
        vector<string> ans;
        string cur = "";
        f(cur, ans, n, leftCnt, rightCnt);
        return ans;
    }
};