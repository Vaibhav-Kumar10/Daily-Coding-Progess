class Solution {
public:
    long long MOD = 1e9 + 7;
    long long numberOfSets(long long n, long long K) {
        if (K == 0) {
            return 1;
        }
        vector<vector<long long>> dp(K + 1, vector<long long>(n + 1, 0));
        for (long long i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (long long k = 1; k <= K; k++) {
            vector<long long> prev_row_suffix_sum(n + 1, 0);
            for (int x = n - 1; x >= 0; x--) {
                prev_row_suffix_sum[x] =
                    (prev_row_suffix_sum[x + 1] + dp[k - 1][x]) % MOD;
            }
            for (long long point = n - 1; point >= 0; point--) {
                // skip point
                long long skip = dp[k][point + 1];
                // start a new segemnt at point
                long long take = prev_row_suffix_sum[point + 1];
                dp[k][point] = (take + skip) % MOD;
            }
        }
        return dp[K][0] % MOD;
    }
    /*
    long long MOD = 1e9 + 7;
    long long numberOfSets(long long n, long long K) {
        if (K == 0) {
            return 1;
        }
        vector<vector<long long>> dp(K + 1, vector<long long>(n + 1, 0));
        for (long long i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (long long k = 1; k <= K; k++) {
            for (long long point = n - 1; point >= 0; point--) {
                // skip point
                long long skip = dp[k][point + 1];
                // start a new segemnt at point
                long long take = 0;
                for (long long next = point + 1; next < n; next++) {
                    take = (take + dp[k - 1][next]) % MOD;
                }
                dp[k][point] = (take + skip) % MOD;
            }
        }
        return dp[K][0] % MOD;
    }
    */
    /*
    long long MOD = 1e9 + 7;
    long long dp[1005][1005];
    long long f(long long point, long long k, long long n) {
        if (k == 0) {
            return 1;
        }
        if (point >= n) {
            return 0;
        }
        if (dp[k][point] != -1) {
            return dp[k][point];
        }
        // start a new segemnt at point
        long long take = 0;
        for (long long next = point + 1; next < n; next++) {
            take = (take + f(next, k - 1, n)) % MOD;
        }
        // skip point
        long long skip = f(point + 1, k, n) % MOD;
        return dp[k][point] = take + skip;
    }
    long long numberOfSets(long long n, long long k) {
        memset(dp, -1, sizeof(dp));
        return f(0, k, n) % MOD;
    }
    */
};