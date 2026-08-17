class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zero_cnt = 0, one_cnt = 0, two_cnt = 0;
        for (int stone : stones) {
            if (stone % 3 == 0) {
                zero_cnt++;
            } else if (stone % 3 == 1) {
                one_cnt++;
            } else if (stone % 3 == 2) {
                two_cnt++;
            }
        }
        // even no. of zeros
        if (zero_cnt % 2 == 0) {
            return (one_cnt > 0 && two_cnt > 0) &&
                   (two_cnt >= one_cnt || two_cnt <= one_cnt);
        }
        // odd no. of zeros
        else {
            return abs(one_cnt - two_cnt) >= 3;
        }
    }
};