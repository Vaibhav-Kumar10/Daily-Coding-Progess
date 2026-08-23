class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), qm_cnt = 0, lh_qm_cnt = 0, rh_qm_cnt = 0;
        int lh_sum = 0, rh_sum = 0;
        for (int i = 0; i < n; i++) {
            char ch = num[i];
            if (ch == '?') {
                qm_cnt++;
                if (i < n / 2) {
                    lh_qm_cnt++;
                } else {
                    rh_qm_cnt++;
                }
            } else {
                if (i < n / 2) {
                    lh_sum += ch - '0';
                } else {
                    rh_sum += ch - '0';
                }
            }
        }
        // Odd '?' => Always Alice gets last turn.
        // => Alice can make the sums unequal by choosing any valid digit
        if (qm_cnt % 2 == 1) {
            return true;
        }
        // Even '?' cnt => Bob always gets the last turn
        // Left and Right side have same no. of '?'
        // If LHS sum == RHS sum
        // => Bob always matches the digit with what Alice has chosen
        // to make the sums equal => Bob wins
        if (lh_qm_cnt == rh_qm_cnt) {
            return lh_sum != rh_sum;
        }

        // Bob can win only if the existing difference can
        // exactly be compensated by the extra '?'.
        int left = 2 * lh_sum + 9 * lh_qm_cnt;
        int right = 2 * rh_sum + 9 * rh_qm_cnt;
        return left != right;
    }
};