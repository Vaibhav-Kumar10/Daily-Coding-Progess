class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }
        string s = to_string(num);
        if (s[0] == '-') {
            sort(s.begin() + 1, s.end());
            reverse(s.begin() + 1, s.end());
        } else {
            sort(s.begin(), s.end());
            int i = 0, n = s.size();
            while (i < n && s[i] == '0') {
                i++;
            }
            swap(s[0], s[i]);
        }
        return stoll(s);
    }
};