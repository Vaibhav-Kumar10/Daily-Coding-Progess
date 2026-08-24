class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        for (int num : nums) {
            string n = to_string(num);
            for (char ch : n) {
                int digit = ch - '0';
                digits.push_back(digit);
            }
        }
        return digits;
    }
    /*
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        for (int num : nums) {
            int n = num;
            vector<int> temp;
            while (n > 0) {
                int digit = n % 10;
                n /= 10;
                temp.push_back(digit);
            }
            reverse(temp.begin(), temp.end());
            digits.insert(digits.end(), temp.begin(), temp.end());
        }
        return digits;
    }
    */
};