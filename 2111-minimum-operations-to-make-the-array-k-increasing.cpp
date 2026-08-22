class Solution {
public:
    int lngst_non_dec_subseq(vector<int>& arr) {
        vector<int> lngst_non_dec_subseq_possible;
        for (int num : arr) {
            // find smallest no. just strictly greater than num,
            // for Longest non decreasing sub seq
            auto it = upper_bound(lngst_non_dec_subseq_possible.begin(),
                                  lngst_non_dec_subseq_possible.end(), num);
            if (it == lngst_non_dec_subseq_possible.end()) {
                lngst_non_dec_subseq_possible.push_back(num);
            } else {
                *it = num;
            }
        }
        return lngst_non_dec_subseq_possible.size();
    }
    /*
    int lngst_non_dec_subseq(vector<int>& arr) {
        int n = arr.size(), lndsq = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] <= arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lndsq = max(lndsq, dp[i]);
        }
        return lndsq;
    }
    */
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ops = 0;
        vector<vector<int>> k_sub_arr(k);
        // partition into k sub arrays =>
        // i, i + k, i + 2k, ...,
        // i + 1, i + 1 + k, i + 1 + 2k, ...,
        // etc.
        for (int i = 0; i < n; i++) {
            k_sub_arr[i % k].push_back(arr[i]);
        }
        for (int i = 0; i < k; i++) {
            // find lngst_non_dec_subseq for each sub array
            // ops req = len - lngst_non_dec_subseq
            // bcz, dif no. of elements are not in order
            ops += k_sub_arr[i].size() - lngst_non_dec_subseq(k_sub_arr[i]);
            // Printing to check
            for (int num : k_sub_arr[i]) {
                cout << num << " ";
            }
            cout << endl;
        }
        return ops;
    }
};