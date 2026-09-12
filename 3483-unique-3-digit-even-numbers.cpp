class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> numbers;
        for (int hundreds = 0; hundreds < n; hundreds++) {
            for (int tens = 0; tens < n; tens++) {
                for (int ones = 0; ones < n; ones++) {
                    if (ones == tens || ones == hundreds || tens == hundreds) {
                        continue;
                    }
                    int num = digits[hundreds] * 100 + digits[tens] * 10 +
                              digits[ones];
                    if (num >= 100 && num % 2 == 0) {
                        numbers.insert(num);
                    }
                }
            }
        }
        return numbers.size();
        ;
    }
    /*
    void f(string cur, vector<int>& digits, set<int>& numbers, int n,
           vector<bool>& visited) {
        if (cur.size() == 3) {
            if (cur[0] != '0') {
                int last_digit = cur[2] - '0';
                if (last_digit % 2 == 0) {
                    numbers.insert(stoi(cur));
                }
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                cur += to_string(digits[i]);
                f(cur, digits, numbers, n, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        set<int> numbers;
        int n = digits.size();
        vector<bool> visited(n, false);
        string num = "";
        f(num, digits, numbers, n, visited);
        return numbers.size();
    }
    */
};