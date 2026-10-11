class Solution {
public:
    bool threeFibonacciSum(int n) {
        int one = 0, two = 1;
        while (one + two <= n) {
            int three = one + two;
            if (one + two + three == n) {
                return true;
            }
            one = two;
            two = three;
        }
        return false;
    }
};