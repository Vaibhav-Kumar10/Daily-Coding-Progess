class Solution {
public:
    unordered_set<int> getPrimeFactors(int num) {
        unordered_set<int> primeFactors;
        for (int pf = 2; pf * pf <= num; pf++) {
            if (num % pf == 0) {
                primeFactors.insert(pf);
                while (num % pf == 0) {
                    num /= pf;
                }
            }
        }
        if (num != 1) {
            primeFactors.insert(num);
        }
        return primeFactors;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), maxLen = 0;
        unordered_map<int, int> pfFreq;
        while (r < n) {
            unordered_set<int> primeFactors = getPrimeFactors(nums[r]);
            for (int pf : primeFactors) {
                pfFreq[pf]++;
            }
            while (l <= r && pfFreq.size() > k) {
                unordered_set<int> pfs = getPrimeFactors(nums[l]);
                for (int pf : pfs) {
                    pfFreq[pf]--;
                    if (pfFreq[pf] == 0) {
                        pfFreq.erase(pf);
                    }
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};