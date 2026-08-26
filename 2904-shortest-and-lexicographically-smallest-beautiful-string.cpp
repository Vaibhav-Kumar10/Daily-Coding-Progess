class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> freq(2, 0);
        int l = 0, r = 0, n = s.length(), minLen = INT_MAX;
        string minStr = "";
        for (r; r < n; r++) {
            freq[s[r] - '0']++;
            while (l <= r && freq[1] > k) {
                freq[s[l] - '0']--;
                l++;
            }
            while (freq[1] == k && l <= r && s[l] == '0') {
                l++;
            }
            if (freq[1] == k) {
                int curLen = r - l + 1;
                if (curLen < minLen) {
                    minLen = curLen;
                    minStr = s.substr(l, curLen);
                } else if (curLen == minLen) {
                    string curStr = s.substr(l, curLen);
                    if (curStr < minStr) {
                        minStr = curStr;
                    }
                }
            }
        }
        return minStr;
    }
};