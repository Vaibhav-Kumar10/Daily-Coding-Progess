class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i], dig_sum = 0;
            while (num > 0) {
                dig_sum += num % 10;
                num /= 10;
            }
            if (dig_sum == i) {
                return i;
            }
        }
        return -1;
    }
};