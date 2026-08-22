class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum = 0, digit_product = 1, num = n;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            digit_sum += digit;
            digit_product *= digit;
        }
        return n % (digit_sum + digit_product) == 0;
    }
};