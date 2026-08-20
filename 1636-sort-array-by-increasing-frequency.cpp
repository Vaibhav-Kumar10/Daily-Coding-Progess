class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        for (int num : nums) {
            numFreq[num]++;
        }
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) {
            if (numFreq[a] == numFreq[b]) {
                return a > b;
            }
            return numFreq[a] < numFreq[b];
        });

        return nums;
    }
};