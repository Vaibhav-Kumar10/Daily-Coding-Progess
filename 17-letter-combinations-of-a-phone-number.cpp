class Solution {
public:
    void f(int ind, string cur, vector<string>& ans,
           unordered_map<char, string> dig2char, string& digits, int n) {
        if (ind == n) {
            ans.push_back(cur);
            return;
        }
        char digit = digits[ind];
        for (auto ch : dig2char[digit]) {
            f(ind + 1, cur + ch, ans, dig2char, digits, n);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<char, string> dig2char = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
        };
        vector<string> ans;
        f(0, "", ans, dig2char, digits, n);
        return ans;
    }
};