class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k,
                                vector<vector<int>>& queries) {
        // valid =>
        // 1. k distinct nums
        // 2. freq of each num is even
        int n = nums.size(), q = queries.size();
        vector<vector<int>> q_c;
        vector<bool> ans(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            q_c.push_back({l, r, i});
        }
        // sort(q_c.begin(), q_c.end());

        // using the Mo's algorithm. else TLE 
        int block_size = max(1, (int)(n / sqrt(q)));
        sort(q_c.begin(), q_c.end(), [&](const auto& a, const auto& b) {
            int block_1 = a[0] / block_size, block_2 = b[0] / block_size;
            if (block_1 == block_2) {
                return block_1 % 2 == 0 ? a[1] > b[1] : a[1] < b[1];
            }
            return block_1 < block_2;
        });

        unordered_map<int, int> freq;
        int cur_l = 0, cur_r = -1, odd_freq_cnt = 0;
        for (auto query : q_c) {
            int l = query[0], r = query[1], i = query[2];

            // expand window from left
            while (cur_l > l) {
                cur_l--;
                freq[nums[cur_l]]++;

                if (freq[nums[cur_l]] % 2 == 1) {
                    odd_freq_cnt++;
                } else {
                    odd_freq_cnt--;
                }
            }

            // expand window from right
            while (cur_r < r) {
                cur_r++;

                freq[nums[cur_r]]++;
                if (freq[nums[cur_r]] % 2 == 1) {
                    odd_freq_cnt++;
                } else {
                    odd_freq_cnt--;
                }
            }

            // shrink window from left
            while (cur_l < l) {
                freq[nums[cur_l]]--;
                if (freq[nums[cur_l]] % 2 == 1) {
                    odd_freq_cnt++;
                } else {
                    odd_freq_cnt--;
                }
                if (freq[nums[cur_l]] == 0) {
                    freq.erase(nums[cur_l]);
                }
                cur_l++;
            }

            // shrink window from left
            while (cur_r > r) {
                freq[nums[cur_r]]--;
                if (freq[nums[cur_r]] % 2 == 1) {
                    odd_freq_cnt++;
                } else {
                    odd_freq_cnt--;
                }
                if (freq[nums[cur_r]] == 0) {
                    freq.erase(nums[cur_r]);
                }
                cur_r--;
            }
            bool isValid = freq.size() == k && odd_freq_cnt == 0;

            if (isValid) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
        return ans;
    }
};