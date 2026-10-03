class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size(), depth = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            // increase depth on opening parenthesis
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2;
            }
            // reduce depth on closing parenthesis
            else if (seq[i] == ')') {
                ans[i] = depth % 2;
                depth--;
            }
        }
        return ans;
    }
};