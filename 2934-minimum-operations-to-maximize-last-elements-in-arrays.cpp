class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        // nums1[-1] and nums2[-1] are already the maximum
        // in the respective their arrays
        int last_not_swapped_swaps = 0, n = nums1.size();
        for (int i = 0; i < n - 1; i++) {
            // nums1[i] is the smaller than or equal to last element in nums1
            // and
            // nums2[i] is the smaller than or equal to last element in nums2
            if (nums1[i] <= nums1[n - 1] && nums2[i] <= nums2[n - 1]) {
                continue;
            }
            // nums1[i] is the smaller than or equal to last element in nums2
            // and
            // nums2[i] is the smaller than or equal to last element in nums1
            else if (nums1[i] <= nums2[n - 1] && nums2[i] <= nums1[n - 1]) {
                last_not_swapped_swaps++;
            }
            // Any other combination
            else {
                last_not_swapped_swaps = INT_MAX;
                break;
            }
        }

        // nums1[-1] and nums2[-1] are not the maximum
        // in the respective their arrays
        int after_last_swaps = 1;
        for (int i = 0; i < n - 1; i++) {
            // nums1[i] is the smaller than or equal to last element in nums2
            // and
            // nums2[i] is the smaller than or equal to last element in nums1
            if (nums1[i] <= nums2[n - 1] && nums2[i] <= nums1[n - 1]) {
                continue;
            }
            // nums1[i] is the smaller than or equal to last element in nums1
            // and
            // nums2[i] is the smaller than or equal to last element in nums2
            else if (nums1[i] <= nums1[n - 1] && nums2[i] <= nums2[n - 1]) {
                after_last_swaps++;
            }
            // Any other combination
            else {
                after_last_swaps = INT_MAX;
                break;
            }
        }

        if (last_not_swapped_swaps == INT_MAX && after_last_swaps == INT_MAX) {
            return -1;
        }
        return min(last_not_swapped_swaps, after_last_swaps);
    }
};