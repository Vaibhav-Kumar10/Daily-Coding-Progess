class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.length();
        vector<int> ans, RHSmatchingLen(n, 0);
        int i = n - 1, j = m - 1, rightMatchCnt = 0;
        // Calculate no of RHS matching chars
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                rightMatchCnt++;
                j--;
            }
            RHSmatchingLen[i] = rightMatchCnt;
            i--;
        }
        bool canChange = true;
        i = 0, j = 0;
        while (i < n && j < m) {
            // If cahrs mathc => move to next
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            // Change one char, if possible and helpfull
            else if (canChange == true && i + 1 < n &&
                     RHSmatchingLen[i + 1] >= (m - j - 1)) {
                ans.push_back(i);
                j++;
                canChange = false;
            }
            i++;
        }
        // If all chars have been matched
        if (j == m) {
            return ans;
        }
        return {};
    }
};