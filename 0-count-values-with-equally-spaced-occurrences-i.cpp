class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> num_freq;
        int n = nums.size(), cnt = 0;
        for (int num : nums) {
            num_freq[num]++;
        }
        for (auto [num, freq] : num_freq) {
            if (freq == 3) {
                vector<int> indices;
                for (int i = 0; i < n; i++) {
                    if (nums[i] == num) {
                        indices.push_back(i);
                    }
                }
                if (indices[1] - indices[0] == indices[2] - indices[1]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};