class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> all_nums(nums.begin(), nums.end());
        int i = 1, multiple = k;
        while (all_nums.find(multiple) != all_nums.end()) {
            i++;
            multiple = k * i;
        }
        return multiple;
    }
};