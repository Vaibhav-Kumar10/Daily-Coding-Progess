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
        vector<int> arr = nums;
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i;
        }
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
            int dig_sum_a = findDigitSum(a), dig_sum_b = findDigitSum(b);
            if (dig_sum_a != dig_sum_b) {
                return dig_sum_a < dig_sum_b;
            }
            return a < b;
        });
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            // wrong pos in nums
            if (arr[i] != nums[i]) {
                // idx of corrrect num at i
                int idx = index[arr[i]];

                // update the index
                index[nums[i]] = idx;
                index[arr[i]] = i;

                // update the nums
                swap(nums[i], nums[idx]);
                swaps++;
            }
        }
        return swaps;
    }
};