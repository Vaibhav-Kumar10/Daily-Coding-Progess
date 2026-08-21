class Solution {
public:
    long long cntSmallerOnLeft_GTE_k(long long num, vector<int>& coins, int k) {
        int n = coins.size();
        long long cnt = 0;
        for (int exprsn = 1; exprsn < (1 << n); exprsn++) {
            long long lcm = 0, order = 0;
            for (int i = 0; i < n; i++) {
                // ith bit set => ith coin taken
                if (exprsn & (1 << i)) {
                    order++;
                    if (lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = (lcm * coins[i]) / (gcd(lcm, coins[i]));
                    }
                }
            }
            if (order % 2 == 0) {
                cnt -= floor(num / lcm);
            } else {
                cnt += floor(num / lcm);
            }
        }
        return cnt >= k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 0;
        long long high = 1LL * (*max_element(coins.begin(), coins.end())) * k;
        while (low + 1 < high) {
            long long mid = low + (high - low) / 2;
            // Left has >= k smaller no.
            // try smaller num
            if (cntSmallerOnLeft_GTE_k(mid, coins, k)) {
                high = mid;
            }
            // try larger num
            else {
                low = mid;
            }
        }
        return high;
    }
};