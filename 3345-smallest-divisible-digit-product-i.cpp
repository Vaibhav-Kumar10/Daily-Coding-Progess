class Solution {
public:
    int prod(int num) {
        int ans = 1;
        while (num) {
            int digit = num % 10;
            num /= 10;
            ans *= digit;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int num = n;
        while (prod(num) % t != 0) {
            num++;
        }
        return num;
    }
};