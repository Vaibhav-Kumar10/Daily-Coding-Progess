class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        // store all diffs
        int n = nums1.size();
        vector<long long> diffs(1e5 + 1, 0);
        for (int i = 0; i < n; i++) {
            diffs[abs(nums1[i] - nums2[i])]++;
        }
        // At most K ops
        // => k1 : +1 in nums1 => equivalent to -1 in nums2
        // => k1 : -1 in nums1 => equivalent to +1 in nums2
        // => k2 : +1 in nums2 => equivalent to -1 in nums1
        // => k2 : -1 in nums2 => equivalent to +1 in nums1
        long long K = k1 + k2;
        for (int dif = 1e5; dif > 0 && K > 0; dif--) {
            if (diffs[dif] == 0) {
                continue;
            }
            long long delta = min(K, diffs[dif]);
            K -= delta;
            diffs[dif] -= delta;
            diffs[dif - 1] += delta;
        }
        long long ans = 0;
        for (long long dif = 1; dif <= 1e5; dif++) {
            ans += (diffs[dif] * dif * dif);
        }
        return ans;
    }
    /*
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int
    k1, int k2) { int n = nums1.size();
        // store all diffs
        priority_queue<long long> diffs;
        for (int i = 0; i < n; i++) {
            diffs.push(abs(nums1[i] - nums2[i]));
        }
        // At most K ops
        // => k1 : +1 in nums1 => equivalent to -1 in nums2
        // => k1 : -1 in nums1 => equivalent to +1 in nums2
        // => k2 : +1 in nums2 => equivalent to -1 in nums1
        // => k2 : -1 in nums2 => equivalent to +1 in nums1
        int K = k1 + k2;
        while (K > 0 && diffs.top() > 0) {
            long long top_dif = diffs.top();
            diffs.pop();
            diffs.push(top_dif - 1);
            K--;
        }
        long long ssd = 0LL;
        while (!diffs.empty()) {
            long long dif = diffs.top();
            diffs.pop();
            ssd += (dif * dif);
        }
        return ssd;
    }
    */
};