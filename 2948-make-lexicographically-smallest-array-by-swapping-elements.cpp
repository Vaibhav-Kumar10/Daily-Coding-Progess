class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        int n = nums.size();

        unordered_map<int, queue<int>> grp_els;
        unordered_map<int, int> grp_no;

        int grp = 0;
        grp_no[arr[0]] = grp;
        grp_els[grp].push(arr[0]);
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] <= limit) {
                grp_els[grp].push(arr[i]);
                grp_no[arr[i]] = grp;
            } else {
                grp++;
                grp_els[grp].push(arr[i]);
                grp_no[arr[i]] = grp;
            }
        }

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int grp = grp_no[num];
            int first_from_grp = grp_els[grp].front();
            grp_els[grp].pop();
            nums[i] = first_from_grp;
        }

        return nums;
    }
    /*
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size(), i = 0;
        while (i < n) {
            int swap_idx = -1, smallest_swap_option = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j] && abs(nums[i] - nums[j]) <= limit) {
                    if (nums[j] < smallest_swap_option) {
                        swap_idx = j;
                        smallest_swap_option = nums[j];
                    }
                }
            }
            if (swap_idx != -1) {
                swap(nums[i], nums[swap_idx]);
            } else {
                i++;
            }
        }
        return nums;
    }
    */
};