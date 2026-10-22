class Solution {
public:
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
};