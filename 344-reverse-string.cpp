class Solution {
public:
    void f(vector<char>& s, int l, int r) {
        if (l > r) {
            return;
        }
        swap(s[l], s[r]);
        f(s, l + 1, r - 1);
    }
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        f(s, l, r);
    }
};