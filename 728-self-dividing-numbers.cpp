class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> self_dividing_nums;
        for (int num = left; num <= right; num++) {
            int tnum = num;
            bool self_dividing = true;
            while (tnum > 0) {
                int digit = tnum % 10;
                tnum /= 10;
                // If it contains 0
                if (digit == 0) {
                    self_dividing = false;
                    break;
                }
                // Not divisible by any digit
                if (num % digit != 0) {
                    self_dividing = false;
                    break;
                }
            }
            if (self_dividing == true) {
                self_dividing_nums.push_back(num);
            }
        }
        return self_dividing_nums;
    }
};