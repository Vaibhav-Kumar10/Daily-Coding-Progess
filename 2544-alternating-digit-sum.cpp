class Solution {
public:
    int alternateDigitSum(int n) {
        string num = to_string(n);
        int digit_sum = 0, sign = 1;
        for (char ch : num) {
            int digit = ch - '0';
            digit_sum += (sign * digit);
            sign *= -1;
        }
        return digit_sum;
    }
};