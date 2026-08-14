class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        unordered_map<char, int> freq;
        for (r; r < n; r++) {
            freq[s[r]]++;
            while (freq[s[r]] > 2) {
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};