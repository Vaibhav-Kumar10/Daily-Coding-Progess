class Solution {
public:
    int freq[26];
    string ans;
    int half_len = 0;
    char mid_ch = '$';
    bool f(int ind, string& cur, string& s, string& target, bool greater) {
        if (cur.size() == half_len) {
            string possible = cur, right_half = cur;
            reverse(begin(right_half), end(right_half));
            if (mid_ch != '$') {
                possible += mid_ch;
            }
            possible += right_half;
            if (possible > target) {
                ans = possible;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0) {
                continue;
            }
            if (!greater && ch < target[ind]) {
                continue;
            }
            cur += ch;
            freq[ch - 'a']--;
            bool isGreater = greater || ch > target[ind];
            if (f(ind + 1, cur, s, target, isGreater)) {
                return true;
            }
            cur.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int odd_freq_cnt = 0;
        for (int i = 0; i < 26; i++) {
            // odd freq
            if (freq[i] % 2 != 0) {
                odd_freq_cnt++;
                if (odd_freq_cnt > 1) {
                    return "";
                }
                mid_ch = i + 'a';
            }
        }
        // half the freq of each ch, to make left half
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }
        ans = "";
        bool greater = false;
        int ind = 0, n = s.size();
        half_len = n / 2;
        string cur = "";
        f(ind, cur, s, target, greater);
        return ans;
    }
};