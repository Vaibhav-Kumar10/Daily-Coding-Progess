class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), cur_sum = 0;
        ;
        int total_sum = (n * (n + 1)) / 2;
        for (int num : nums) {
            cur_sum += num;
        }
        return total_sum - cur_sum;
    }
};
