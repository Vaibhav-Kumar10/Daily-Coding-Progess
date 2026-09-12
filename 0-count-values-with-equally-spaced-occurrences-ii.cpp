class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> num_freq;
        unordered_map<int, vector<int>> num_indices;
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            num_freq[nums[i]]++;
            num_indices[nums[i]].push_back(i);
        }
        unordered_map<int, bool> is_special;
        for (auto [num, indices] : num_indices) {
            if (indices.size() < 3) {
                continue;
            }
            bool special = true;
            for (int i = 1; i < indices.size() - 1; i++) {
                if (indices[i] - indices[i - 1] !=
                    indices[i + 1] - indices[i]) {
                    special = false;
                }
            }
            is_special[num] = special;
        }
        for (auto [num, freq] : num_freq) {
            if (freq >= 3) {
                if (is_special[num]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};