class Solution {
public:
    int kthGrammar(int n, int k) {
        // 2 ^ n-1 => the string
        // row is doubling, and appending inverse of previous row
        // starting from row 1 => '0'
        // row 2 => '01'
        // row 3 => '01 10'
        // row 4 => '01 10 01 10'
        if (n == 1 && k == 1) {
            return 0;
        }
        int len = (1 << (n - 1));
        int mid = len / 2;
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        }
        return !kthGrammar(n - 1, k - mid);
    }
    /*
    string generateRow(int n) {
        if (n == 1) {
            return "0";
        }
        string prevRow = generateRow(n - 1);
        string curRow = "";
        for (char ch : prevRow) {
            if (ch == '0') {
                curRow.push_back('0');
                curRow.push_back('1');
            } else {
                curRow.push_back('1');
                curRow.push_back('0');
            }
        }
        return curRow;
    }
    int kthGrammar(int n, int k) {
        string row = generateRow(n);
        return row[k - 1] - '0';
    }
    */
};