class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), maxLen = -1;
        if (n == 0) {
            return 0;
        }
        unordered_map<char, int> freq;
        while (r < n) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) {
                    freq.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, (r - l + 1));
            r++;
        }
        return maxLen;
    }
};