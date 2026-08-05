class Solution {
public:
    bool isSame(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0}, freq2[26] = {0};
        int n = s1.size(), m = s2.size();
        if (n > m) {
            return false;
        }
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            char ch = s2[i];
            freq2[ch - 'a']++;
        }
        if (isSame(freq1, freq2)) {
            return true;
        }
        for (int i = n; i < m; i++) {
            char ch = s2[i], left_char = s2[i - n];
            freq2[ch - 'a']++;
            freq2[left_char - 'a']--;
            if (isSame(freq1, freq2)) {
                return true;
            }
        }
        return false;
    }
};