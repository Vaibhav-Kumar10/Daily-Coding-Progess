class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // even idx => max
        // odd idx => min
        vector<long long> squares;
        for (int num : nums) {
            squares.push_back(1LL * num * num);
        }
        sort(squares.rbegin(), squares.rend());
        long long ans = 0;
        int n = squares.size();
        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                ans += squares[i];
            } else {
                ans -= squares[i];
            }
        }
        return ans;
    }
};