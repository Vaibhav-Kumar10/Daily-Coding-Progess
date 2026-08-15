class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> distinct_sub_arr;
        for (int i = 0; i < n; i++) {
            int div_by_p = 0;
            vector<int> sub_arr;
            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0) {
                    div_by_p++;
                }
                if (div_by_p > k) {
                    break;
                }
                sub_arr.push_back(nums[j]);
                distinct_sub_arr.insert(sub_arr);
            }
        }
        return distinct_sub_arr.size();
    }
};