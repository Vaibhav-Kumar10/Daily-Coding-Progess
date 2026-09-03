class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size(), evenCnt = 0, oddCnt = 0, minEl = INT_MAX;
        if (n == 1) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            minEl = min(minEl, nums1[i]);
            if (nums1[i] % 2 == 0) {
                evenCnt++;
            } else {
                oddCnt++;
            }
        }
        if (oddCnt == 0 || evenCnt == 0) {
            return true;
        }
        return minEl % 2 == 1;
    }
};