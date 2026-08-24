class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for (char ch : s) {
            int ch2num = ch - 'a' + 1;
            while (ch2num > 0) {
                int digit = ch2num % 10;
                ch2num /= 10;
                num += digit;
            }
        }
        k--;
        while (k--) {
            int digit_sum = 0;
            while (num > 0) {
                int digit = num % 10;
                num /= 10;
                digit_sum += digit;
            }
            num = digit_sum;
        }
        return num;
    }
};