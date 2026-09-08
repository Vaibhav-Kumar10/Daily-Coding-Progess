class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), l = 0, r = 0;
        int min_len = INT_MAX, cnt = 0, start_index = -1;
        unordered_map<char, int> freq;
        for (char ch : t) {
            freq[ch]++;
        }
        for (r; r < n; r++) {
            // A req char is found
            if (freq[s[r]] > 0) {
                cnt++;
            }
            freq[s[r]]--;
            // No. of req char found =>
            // until the current sub str has t present,
            // shrink window
            while (cnt == m) {
                int cur_len = r - l + 1;
                if (cur_len < min_len) {
                    min_len = cur_len;
                    start_index = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        if (start_index == -1) {
            return "";
        }
        return s.substr(start_index, min_len);
    }
};