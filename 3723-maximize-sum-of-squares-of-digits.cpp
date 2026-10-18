class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int nines = sum / 9, rem = sum % 9;
        string ans(nines, '9');
        if (rem > 0) {
            ans.push_back(rem + '0');
        }
        int left = num - ans.length();
        ans.append(left, '0');
        return ans;
    }
};