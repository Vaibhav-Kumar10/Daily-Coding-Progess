class Solution {
public:
    int countEven(int num) {
        int cnt = 0;
        for (int no = 1; no <= num; no++) {
            int digit_sum = 0, n = no;
            while (n > 0) {
                int digit = n % 10;
                n /= 10;
                digit_sum += digit;
            }
            if (digit_sum % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};