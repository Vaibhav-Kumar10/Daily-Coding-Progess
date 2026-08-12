class Solution {
public:
    int cntSubarrWithSumLTEgoal(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size(), cur_sum = 0, sub_arr_cnt = 0;
        for (r; r < n; r++) {
            cur_sum += nums[r];
            while (l <= r && cur_sum > goal) {
                cur_sum -= nums[l];
                l++;
            }
            sub_arr_cnt += (r - l + 1);
        }
        return sub_arr_cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // (No. of subb with sum <= goal)
        // -
        // (No. of sub arr with sum <= goal - 1)
        // = (No. of sub arr with sum == goal)
        return cntSubarrWithSumLTEgoal(nums, goal) -
               cntSubarrWithSumLTEgoal(nums, goal - 1);
    }
};