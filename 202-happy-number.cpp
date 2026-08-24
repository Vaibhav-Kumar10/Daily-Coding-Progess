class Solution {
public:
    int sumDigitSq(int num) {
        int tnum = num, sumDigitSqr = 0;
        while (tnum) {
            int digit = tnum % 10;
            sumDigitSqr += (digit * digit);
            tnum /= 10;
        }
        return sumDigitSqr;
    }
    bool isHappy(int n) {
        set<int> happySet;
        while (true) {
            if (n == 1) {
                return true;
            }
            n = sumDigitSq(n);

            if (happySet.find(n) != happySet.end()) {
                return false;
            }
            happySet.insert(n);
        }
    }
};