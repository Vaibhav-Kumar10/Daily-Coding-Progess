class Solution {
public:
    bool checkPerfectNumber(int num) {
        int divisor_sum = 0;
        for (int divisor = 1; divisor < num; divisor++) {
            if (num % divisor == 0) {
                divisor_sum += divisor;
            }
        }
        return divisor_sum == num;
    }
};