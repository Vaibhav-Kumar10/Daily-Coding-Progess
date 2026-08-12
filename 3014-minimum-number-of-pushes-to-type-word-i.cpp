class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> dig2char;
        int key = 2, n = word.size(), presses = 0;
        for (char ch : word) {
            if (key > 9) {
                key = 2;
            }
            dig2char[key]++;
            presses += dig2char[key];
            key++;
        }
        return presses;
    }
};