class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int n = pairs.size(), count = 0, last_end = -99999999;

        for (int i = 0; i < n; ++i) {
            if (pairs[i][0] > last_end) {
                count++;
                last_end = pairs[i][1];
            }
        }

        return count;
        ;
    }
};