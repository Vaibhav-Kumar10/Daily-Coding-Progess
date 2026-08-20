class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        for (int num : nums) {
            numFreq[num]++;
        }

        for (auto [num, freq] : numFreq) {
            if (freq % 2 == 1) {
                return false;
            }
        }
        return true;
    }
};