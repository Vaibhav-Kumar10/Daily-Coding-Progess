class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int divisor_sum = 0;
        for (int divisor = 1; divisor < num; divisor++) {
            if (num % divisor == 0) {
                divisor_sum += divisor;
            }
            if (divisor_sum > num) {
                return false;
            }
        }
        return divisor_sum == num;
    }
};