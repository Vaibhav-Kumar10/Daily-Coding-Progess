class Solution {
public:
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
};