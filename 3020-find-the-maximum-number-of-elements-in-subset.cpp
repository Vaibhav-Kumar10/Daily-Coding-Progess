class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int n = nums.size(), maxLen = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int len = 0;
            long long num = nums[i];
            if (num == 1) {
                len = freq[1] % 2 == 1 ? freq[1] : freq[1] - 1;
                maxLen = max(maxLen, len);
                continue;
            }
            // check if num ^ 2 exists, then increase the len by 2,
            // as num should be used 2 times => before and after
            while (freq.find(num * num) != freq.end() && freq[num] > 1) {
                len += 2;
                num = num * num;
            }
            // if num^2 is found
            // => it can be used only once for middle with freq 1
            if (freq.find(num) != freq.end()) {
                len++;
            }
            // if num^2 not found => the most middle num can't be used twice
            else {
                len--;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};