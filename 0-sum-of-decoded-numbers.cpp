class Solution {
public:
    int MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long dec_sum = 0;
        for (int i = 0; i < n; i++) {
            long long num = nums[i];
            long long d = floor(num / 10);
            long long width = num % 10;
            // d = _ _ _ _ _ _ _ .... _ _ _ _
            //    <----x-----> <------y----->
            // x = width no. of digits
            // y = total - width no. of digits;
            long long no_of_d = 0, tnum = d;
            while (tnum) {
                no_of_d++;
                tnum /= 10;
            }

            // 2 3 0 1 , width = 1
            // 2 , 3 0 1
            long long ten_pow = pow(10, no_of_d - width);
            long long x = d / ten_pow;
            long long y = d % ten_pow;

            long long decoded = power(x, y);
            dec_sum = (dec_sum + decoded) % MOD;
        }
        return dec_sum;
    }
};