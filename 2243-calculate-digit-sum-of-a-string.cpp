class Solution {
public:
    string digitSum(string s, int k) {
        if (s.size() <= k) {
            return s;
        }
        string cur = "";
        for (int i = 0; i < s.size(); i += k) {
            string num = s.substr(i, k);
            int digit_sum = 0;
            for (char ch : num) {
                digit_sum += ch - '0';
            }
            cur += to_string(digit_sum);
        }
        return digitSum(cur, k);
    }
};