class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int alt_sum = 0, sign = 1;
        for (int num : nums) {
            alt_sum += (sign * num);
            sign *= -1;
        }
        return alt_sum;
    }
};