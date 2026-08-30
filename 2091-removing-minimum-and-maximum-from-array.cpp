class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = -1, max_idx = -1, min_num = INT_MAX, max_num = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] < min_num) {
                min_num = nums[i];
                min_idx = i;
            }
            if (nums[i] > max_num) {
                max_num = nums[i];
                max_idx = i;
            }
        }
        int min_l2r = min_idx + 1, min_r2l = n - min_idx;
        int max_l2r = max_idx + 1, max_r2l = n - max_idx;

        int rem_all_from_l = max(max_l2r, min_l2r);
        int rem_all_from_r = max(max_r2l, min_r2l);

        int rem_alg_alg = min(min_l2r, min_r2l) + min(max_l2r, max_r2l);

        cout << min_l2r << " " << min_r2l << " " << min_idx << endl;
        cout << max_l2r << " " << max_r2l << " " << max_idx << endl;
        cout << rem_all_from_l << " " << rem_all_from_r << " "  << rem_alg_alg << endl;
        return min({rem_all_from_l, rem_all_from_r, rem_alg_alg});
    }
};