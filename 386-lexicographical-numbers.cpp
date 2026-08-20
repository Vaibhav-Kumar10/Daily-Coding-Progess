class Solution {
public:
    void dfs(int num, int n, vector<int>& ans) {
        if (num > n) {
            return;
        }
        ans.push_back(num);
        for (int digit = 0; digit < 10; digit++) {
            int new_num = num * 10 + digit;
            if (new_num <= n) {
                dfs(new_num, n, ans);
            } else {
                break;
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int digit = 1; digit < 10; digit++) {
            if (digit > n) {
                break;
            }
            dfs(digit, n, ans);
        }
        return ans;
    }
};