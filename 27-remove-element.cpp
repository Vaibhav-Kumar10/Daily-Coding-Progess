class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int correct = 0, n = nums.size();;
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[correct] = nums[i];
                correct++;
            }
        }
        return correct;
        /*
        int n = nums.size();
        int r = n - 1, l = 0, cnt = 0;
        while (l <= r) {
            if (nums[l] == val) {
                swap(nums[l], nums[r]);
                r--;
            } else {
                l++;
            }
        }
        return l;
        */
    }
};