class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> all_nums(nums.begin(), nums.end());
        int longest = 0;
        for (int num : all_nums) {
            // If previous no. is not present in the set.
            if (all_nums.find(num - 1) == all_nums.end()) {
                int x = num, cnt = 1;
                // Find the longest sequence in which next number is present
                while (all_nums.find(x + 1) != all_nums.end()) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;

        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n; i++) {
        //     if(prevSmallest == nums[i] - 1){
        //         cnt++;
        //         prevSmallest = nums[i];
        //     }
        //     else if(prevSmallest != nums[i]){
        //         prevSmallest = nums[i];
        //         cnt = 1;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;

        // for (int i = 0; i < nums.size(); i++) {
        //     int cnt = 1, x = nums[i];
        //     while (search(x + 1, nums) == true) {
        //         x++;
        //         cnt++;
        //     }
        //     longest = max(longest, cnt);
        // }
        // return longest;
    }
    // bool search(int el, vector<int> arr) {
    //     for (int i : arr) {
    //         if (i == el) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};