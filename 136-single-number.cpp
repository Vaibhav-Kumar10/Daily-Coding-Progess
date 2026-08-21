class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int el : nums) {
            freq[el]++;
        }
        for (auto it : freq) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
    /*
    int singleNumber(vector<int>& nums) {
        for (int el : nums) {
            int cnt = 0;
            for (int sel : nums) {
                if (el == sel) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                return el;
            }
        }
        return 1;
    }
    */
};