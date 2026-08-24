class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        int last_digit = num % 10;
        int quotient_num = num / 10;

        return addDigits(last_digit + addDigits(quotient_num));
    }
};