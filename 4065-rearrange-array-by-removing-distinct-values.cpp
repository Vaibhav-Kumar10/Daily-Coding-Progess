class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101, 0);
        int n = nums.size(), max_freq = 0;
        for (int num : nums) {
            freq[num]++;
            max_freq = max(max_freq, freq[num]);
        }
        vector<int> ans;
        while (max_freq--) {
            for (int num = 1; num <= 100; num++) {
                if (freq[num] > 0) {
                    ans.push_back(num);
                    freq[num]--;
                }
            }
        }
        return ans;
    }
};