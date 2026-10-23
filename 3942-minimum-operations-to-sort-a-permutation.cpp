class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), asc_cnt = 0, desc_cnt = 0;
        if (n == 1) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            asc_cnt += (nums[i] == (nums[i - 1] + 1) % n);
            desc_cnt += (nums[i - 1] == (nums[i] + 1) % n);
        }
        if (asc_cnt == n - 1 && nums[0] == 0) {
            return 0;
        }
        if (asc_cnt == n - 1) {
            // sorted in asc order
            int lr = n - nums[0];
            int rr = 1 + (nums.back() + 1) + 1;
            return min(lr, rr);
        }
        if (desc_cnt == n - 1) {
            // sorted in desc order
            int lr = n - nums.back() + 1;
            int rr = (nums[0] + 1) % n + 1;
            return min(lr, rr);
        }
        return -1;
    }
    /*
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool isAsc = true, isDesc = true;

        for (int i = 1; i < n; i++) {
            int value = nums[(start + i) % n];

            if (value != i) {
                isAsc = false;
            }
            if (value != n - i) {
                isDesc = false;
            }

            if (!isAsc && !isDesc) {
                return -1;
            }
        }

        if (isAsc) {
            return min(start, n - start + 2);
        }
        return min(n - start, start + 2);
    }
    */
};