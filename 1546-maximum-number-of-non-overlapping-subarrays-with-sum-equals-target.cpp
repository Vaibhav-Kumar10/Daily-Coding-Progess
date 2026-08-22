class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> prevOcc;
        prevOcc.insert(0);
        int curSum = 0, sub_arr_cnt = 0;
        for (int num : nums) {
            curSum += num;
            int req = curSum - target;
            if (prevOcc.find(req) != prevOcc.end()) {
                sub_arr_cnt++;
                prevOcc.clear();
                prevOcc.insert(0);
                curSum = 0;
            } else {
                prevOcc.insert(curSum);
            }
        }
        return sub_arr_cnt;
    }
};