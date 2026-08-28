class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int digit_sum = 0, tnum = x;
        while (tnum) {
            int digit = tnum % 10;
            tnum /= 10;
            digit_sum += digit;
        }
        return x % digit_sum == 0 ? digit_sum : -1;
    }
};