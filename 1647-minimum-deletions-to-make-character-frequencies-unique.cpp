class Solution {
public:
    int minDeletions(string s) {
        unordered_set<int> exists;
        int del_cnt = 0;
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                continue;
            }
            int ch_cnt = freq[i];
            while (ch_cnt > 0 && exists.find(ch_cnt) != exists.end()) {
                ch_cnt--;
                del_cnt++;
            }
            if (ch_cnt > 0) {
                exists.insert(ch_cnt);
            }
        }
        return del_cnt;
    }
};