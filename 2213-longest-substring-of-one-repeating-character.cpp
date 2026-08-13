class Solution {
public:
    struct Node {
        int pref = 0, suff = 0, maxLen = 0;
        char leftChar = 0, rightChar = 0;
    };
    int n;
    vector<Node> segmentTree;
    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            segmentTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segmentTree[i] = merge(segmentTree[2 * i + 1], segmentTree[2 * i + 2],
                               mid - l + 1, r - mid);
    }
    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) {
            segmentTree[i] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segmentTree[i] = merge(segmentTree[2 * i + 1], segmentTree[2 * i + 2],
                               mid - l + 1, r - mid);
    }
    Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
        Node ans;
        ans.leftChar = L.leftChar;
        ans.rightChar = R.rightChar;

        ans.pref = L.pref;
        if (L.pref == leftLen && L.rightChar == R.leftChar) {
            ans.pref = L.pref + R.pref;
        }

        ans.suff = R.suff;
        if (R.suff == rightLen && L.rightChar == R.leftChar) {
            ans.suff = L.suff + R.suff;
        }

        ans.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            ans.maxLen = max(ans.maxLen, L.suff + R.pref);
        }
        return ans;
    }
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int k = queryIndices.size();
        n = s.size(), segmentTree.assign(4 * n, Node());
        buildSegmentTree(0, 0, n - 1, s);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n - 1, pos, ch);
            ans.push_back(segmentTree[0].maxLen);
        }
        return ans;
    }
};