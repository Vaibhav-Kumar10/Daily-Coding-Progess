class Solution {
public:
    int findDigitSum(int num) {
        int tnum = num, dig_sum = 0;
        while (tnum > 0) {
            int digit = tnum % 10;
            tnum /= 10;
            dig_sum += digit;
        }
        return dig_sum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> index;
        int n = nums.size();
        vector<int> sorted = nums;
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i;
        }
        sort(sorted.begin(), sorted.end(), [&](const int& a, const int& b) {
            int dig_sum_a = findDigitSum(a), dig_sum_b = findDigitSum(b);
            if (dig_sum_a != dig_sum_b) {
                return dig_sum_a < dig_sum_b;
            }
            return a < b;
        });
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            // wrong pos in nums
            if (sorted[i] != nums[i]) {
                // idx of corrrect num at i
                int idx = index[sorted[i]];

                // update the index
                index[nums[i]] = idx;
                index[sorted[i]] = i;

                // update the nums
                swap(nums[i], nums[idx]);
                swaps++;
            }
        }
        return swaps;
    }
};