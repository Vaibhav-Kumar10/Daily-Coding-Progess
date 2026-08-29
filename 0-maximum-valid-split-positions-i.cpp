class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int max_score = 0;
        for (int rem_idx = 0; rem_idx <= n; rem_idx++) {
            // no removals => idx = n
            // create a new array with the specified operation
            // => removing at most one num
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if (i == rem_idx) {
                    continue;
                }
                arr.push_back(nums[i]);
            }
            int m = arr.size();
            vector<int> prefixGCD(m);
            vector<int> suffixGCD(m);
            prefixGCD[0] = arr[0];
            suffixGCD[m - 1] = arr[m - 1];
            for (int i = 1; i < m; i++) {
                prefixGCD[i] = gcd(prefixGCD[i - 1], arr[i]);
            }
            for (int i = m - 2; i >= 0; i--) {
                suffixGCD[i] = gcd(suffixGCD[i + 1], arr[i]);
            }
            int cnt = 0;
            for (int i = 0; i < m - 1; i++) {
                if (prefixGCD[i] == suffixGCD[i + 1]) {
                    cnt++;
                }
            }
            max_score = max(max_score, cnt);
        }
        return max_score;
    }
};