class Solution {
public:
    int cntSubarrWithLTEkdistinct(vector<int>& nums, int n, int k) {
        int l = 0, r = 0, sub_arr_cnt = 0;
        unordered_map<int, int> freq;
        for (r; r < n; r++) {
            freq[nums[r]]++;
            while (l <= r && freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }
            sub_arr_cnt += (r - l + 1);
        }
        return sub_arr_cnt;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size(), n_distinct = st.size();
        return cntSubarrWithLTEkdistinct(nums, n, n_distinct) -
               cntSubarrWithLTEkdistinct(nums, n, n_distinct - 1);
    }
};