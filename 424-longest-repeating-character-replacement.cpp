class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), max_len = -1, max_freq = -1, l = 0, r = 0;
        vector<int> freq(26, 0);
        for (r; r < n; r++) {
            freq[s[r] - 'A']++;
            max_freq = max(max_freq, freq[s[r] - 'A']);
            while (l <= r && ((r - l + 1 - max_freq) > k)) {
                freq[s[l] - 'A']--;
                max_freq = *max_element(freq.begin(), freq.end());
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
    /*
    int characterReplacement(string s, int k) {
        int n = s.size(), max_len = -1;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            int max_freq = -1;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                max_freq = max(max_freq, freq[s[j]]);
                int cur_len = j - i + 1;
                int flips_req = cur_len - max_freq;
                if (flips_req <= k) {
                    max_len = max(max_len, cur_len);
                }
            }
        }
        return max_len;
    }
    */
};