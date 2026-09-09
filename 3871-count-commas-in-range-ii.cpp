class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        }
        long long lower = 1000, comma_range = 1, comma_count = 0;
        while (lower <= n) {
            long long upper = lower * 1000 - 1;
            if (upper > n) {
                upper = n;
            }
            long long cnt = upper - lower + 1;
            comma_count += (cnt * comma_range);
            comma_range++;
            lower *= 1000;
        }
        return comma_count;
    }
};