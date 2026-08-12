class Solution {
public:
    int minimumPushes(string word) {
        // Store frequencies
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        // Sort in descending order
        sort(rbegin(freq), rend(freq));
        int n = word.size(), presses = 0;
        for (int i = 0; i < 26; i++) {
            int f = freq[i];
            presses += (i / 8 + 1) * f;
        }
        return presses;
    }
};