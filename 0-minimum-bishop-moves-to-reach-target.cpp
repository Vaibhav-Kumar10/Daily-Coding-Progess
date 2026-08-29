class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int cur_row = source[0], cur_col = source[1];
        int target_row = target[0], target_col = target[1];
        // current row and col are same parity => white box
        // even + even => even
        // odd + odd => even
        // current row and col are different parity => black box

        // if target's color != current color => not possible
        if (((cur_row + cur_col) % 2) != ((target_row + target_col) % 2)) {
            return -1;
        }
        // they have same color

        else {
            // same diagonal
            if (cur_row + cur_col == target_row + target_col) {
                return 1;
            } else if ((cur_row - cur_col) == (target_row - target_col)) {
                return 1;
            }
            // different diagonal
            else {
                return 2;
            }
        }
    }
};