class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> nseSt, pseSt;
        int n = arr.size(), MOD = 1e9 + 7, sum = 0;
        vector<int> nse_idx(n), pse_idx(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!nseSt.empty() && arr[nseSt.top()] >= arr[i]) {
                nseSt.pop();
            }
            nse_idx[i] = nseSt.empty() ? n : nseSt.top();
            nseSt.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!pseSt.empty() && arr[pseSt.top()] > arr[i]) {
                pseSt.pop();
            }
            pse_idx[i] = pseSt.empty() ? -1 : pseSt.top();
            pseSt.push(i);
        }
        for (int i = 0; i < n; i++) {
            int left = i - pse_idx[i], right = nse_idx[i] - i;
            sum = (sum + (left * right * 1LL * arr[i]) % MOD) % MOD;
        }
        return sum;
    }
};