class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> freq, freq_2;
        unordered_map<int, bool> special;
        for (int num : nums) {
            freq[num]++;
            special[num] = false;
        }
        int n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            freq_2[nums[i]]++;
            if (i == n - 1 || nums[i] != nums[i + 1]) {
                if (freq_2[nums[i]] == freq[nums[i]]) {
                    special[nums[i]] = true;
                    cnt++;
                } else {
                    special[nums[i]] = false;
                }
                freq_2[nums[i]] = 0;
            }
            // int j = i;
            // bool no_c = false;
            // while(j < n) {
            //     if(nums[i] != nums[j]) {
            //         j++;
            //     }
            // }
        }
        return cnt;
    }
};