class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long a = nums[i], b = nums[j];
                long long prod = a * b;
                long long denom = gcd(a, b);
                long long cur = prod / (denom * denom);
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};