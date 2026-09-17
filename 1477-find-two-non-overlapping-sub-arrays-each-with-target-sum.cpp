class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0, r = 0, n = arr.size();
        int cur_sum = 0, min_len = INT_MAX, min_len_sum = INT_MAX;
        vector<int> minLenTillIndex(n, INT_MAX);
        for (r; r < n; r++) {
            cur_sum += arr[r];
            while (l <= r && cur_sum > target) {
                cur_sum -= arr[l];
                l++;
            }
            if (cur_sum == target) {
                int cur_len = r - l + 1;
                if (l > 0 && minLenTillIndex[l - 1] != INT_MAX) {
                    min_len_sum =
                        min(min_len_sum, cur_len + minLenTillIndex[l - 1]);
                }
                min_len = min(min_len, cur_len);
            }
            minLenTillIndex[r] = min_len;
        }
        return min_len_sum == INT_MAX ? -1 : min_len_sum;
    }
};