class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_nums = 0, xor_total = n;
        for (int i = 0; i < n; i++) {
            // XOR of array elements
            xor_nums ^= nums[i];
            // XOR up to [1...N-1]
            xor_total ^= i;
        }
        return xor_total ^ xor_nums;
    }
    /*
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), cur_sum = 0;
        int total_sum = (n * (n + 1)) / 2;
        for (int num : nums) {
            cur_sum += num;
        }
        return total_sum - cur_sum;
    }
    */
};
