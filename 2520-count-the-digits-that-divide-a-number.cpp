class Solution {
public:
    int countDigits(int num) {
        int tnum = num, cnt = 0;
        while (tnum > 0) {
            int digit = tnum % 10;
            tnum /= 10;
            if (num % digit == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};