class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string ans = "";
        while (num1 > 0 || num2 > 0 || num3 > 0) {
            int num1_digit = num1 % 10;
            num1 /= 10;
            int num2_digit = num2 % 10;
            num2 /= 10;
            int num3_digit = num3 % 10;
            num3 /= 10;
            int min_dig = min({num1_digit, num2_digit, num3_digit});
            ans += to_string(min_dig);
        }
        reverse(begin(ans), end(ans));
        return stoi(ans);
    }
};