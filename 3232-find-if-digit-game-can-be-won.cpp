class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int one_digit_num_sum = 0, two_digit_num_sum = 0;
        for (int num : nums) {
            if (num < 10) {
                one_digit_num_sum += num;
            } else {
                two_digit_num_sum += num;
            }
        }
        if (one_digit_num_sum == two_digit_num_sum) {
            return false;
        }
        // Alice can choose the larger sum
        return true;
        // return one_digit_num_sum != two_digit_num_sum;
    }
};