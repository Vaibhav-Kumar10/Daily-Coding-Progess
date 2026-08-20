class Solution {
public:
    int dp[100005][2];
    int f(int ind, bool swapped, vector<int>& nums1, vector<int>& nums2,
          int n) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][swapped] != -1) {
            return dp[ind][swapped];
        }
        int prev1 = nums1[ind - 1], prev2 = nums2[ind - 1];
        if (swapped) {
            swap(prev1, prev2);
        }
        int ans = INT_MAX;
        // Strictly increasing in both => No swap required
        if (nums1[ind] > prev1 && nums2[ind] > prev2) {
            ans = min(ans, f(ind + 1, false, nums1, nums2, n));
        }
        // Not strictly increasing in both => Swap required
        if (nums1[ind] > prev2 && nums2[ind] > prev1) {
            ans = min(ans, 1 + f(ind + 1, true, nums1, nums2, n));
        }
        return dp[ind][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ind = 1;
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        memset(dp, -1, sizeof(dp));
        bool swapped = false;
        return f(ind, swapped, nums1, nums2, n + 1);
    }
    /*
    int f(int prev1, int prev2, int ind, vector<int>& nums1, vector<int>& nums2,
          int n) {
        if (ind == n) {
            return 0;
        }
        int ans = INT_MAX;
        // Strictly increasing in both => No swap required
        if (nums1[ind] > prev1 && nums2[ind] > prev2) {
            ans = min(ans, f(nums1[ind], nums2[ind], ind + 1, nums1, nums2, n));
        }
        // Not strictly increasing in both => Swap required
        if (nums1[ind] > prev2 && nums2[ind] > prev1) {
            ans = min(ans,
                      1 + f(nums2[ind], nums1[ind], ind + 1, nums1, nums2, n));
        }
        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), prev1 = -1, prev2 = -1, ind = 0;
        return min(f(prev1, prev2, ind, nums1, nums2, n),
                   f(prev1, prev2, ind, nums1, nums2, n));
    }
    */
};