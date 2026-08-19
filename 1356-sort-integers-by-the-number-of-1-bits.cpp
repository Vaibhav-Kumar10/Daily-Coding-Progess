class Solution {
public:
    int countOnes(int num) {
        int tnum = num, cnt = 0;
        while (tnum > 0) {
            if (tnum % 2 == 1) {
                cnt++;
            }
            tnum /= 2;
        }
        return cnt;
    }
    bool comp(const int a, const int b) {
        int oneCountA = countOnes(a), oneCountB = countOnes(b);
        if (oneCountA == oneCountB) {
            return a < b;
        }
        return oneCountA < oneCountB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) { return comp(a, b); });
        return arr;
    }
};