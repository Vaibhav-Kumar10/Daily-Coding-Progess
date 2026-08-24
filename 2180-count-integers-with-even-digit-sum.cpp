class Solution {
public:
    int countEven(int num) {
        int digit_sum = 0, original_num = num;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            digit_sum += digit;
        }
        // if cur num -> sum of digits is even
        // => num / 2 no. have even sum
        //
        // if cur num -> sum of digits is odd
        // => (num - 1) / 2 no. have even sum
        //
        if (digit_sum % 2 == 0) {
            return original_num / 2;
        }
        return (original_num - 1) / 2;
    }
    /*
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
    */
};