class Solution {
public:
    int smallestValue(int n) {
        int prime_factor_sum = 0, original = n;
        for (int divisor = 2; divisor <= n; divisor++) {
            while (n % divisor == 0) {
                prime_factor_sum += divisor;
                n /= divisor;
            }
        }
        if (original == prime_factor_sum) {
            return original;
        }
        return smallestValue(prime_factor_sum);
    }
};