class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> occupiedGrpInRow;
        for (auto row_res_seat : reservedSeats) {
            int row = row_res_seat[0], seat = row_res_seat[1];
            occupiedGrpInRow[row] |= (1 << seat);
        }
        int nonEmptyRows = occupiedGrpInRow.size();
        int emptyRows = n - nonEmptyRows;
        // For empty row => Group 1 and Group 2 can be booked
        int maxGrps = 2 * emptyRows;

        // Bit masks for Group 1: seats 2,3,4,5
        int grp_1_mask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        // Bit masks for Group 2: seats 4,5,6,7
        int grp_2_mask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        // Bit masks for Group 3: seats 6,7,8,9
        int grp_3_mask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto [row, grpOccupiedMask] : occupiedGrpInRow) {
            bool grp_1_possible = (grp_1_mask & grpOccupiedMask) == 0;
            bool grp_2_possible = (grp_2_mask & grpOccupiedMask) == 0;
            bool grp_3_possible = (grp_3_mask & grpOccupiedMask) == 0;
            // Group 1 and Group 3 can be booked
            if (grp_1_possible && grp_3_possible) {
                maxGrps += 2;
            }
            // Only one of the Gropus 1, 2, and 3 can be booked
            else if (grp_1_possible || grp_2_possible || grp_3_possible) {
                maxGrps += 1;
            }
        }
        return maxGrps;
    }
    /*
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> occupiedGrpInRow;
        for (auto row_res_seat : reservedSeats) {
            int row = row_res_seat[0], seat = row_res_seat[1];
            if (occupiedGrpInRow.find(row) == occupiedGrpInRow.end()) {
                occupiedGrpInRow[row] = vector<bool>{false, false, false};
            }
            // Group 1: seats 2,3,4,5 - can't be booked
            if (seat >= 2 && seat <= 5) {
                occupiedGrpInRow[row][0] = true;
            }
            // Group 2: seats 4,5,6,7 - can't be booked
            if (seat >= 4 && seat <= 7) {
                occupiedGrpInRow[row][1] = true;
            }
            // Group 3: seats 6,7,8,9 - can't be booked
            if (seat >= 6 && seat <= 9) {
                occupiedGrpInRow[row][2] = true;
            }
        }
        int nonEmptyRows = occupiedGrpInRow.size();
        int emptyRows = n - nonEmptyRows;
        // For empty row => Group 1 and Group 2 can be booked
        int maxGrps = 2 * emptyRows;
        for (auto [row, grpOccupied] : occupiedGrpInRow) {
            // Group 1 and Group 3 can be booked
            if (grpOccupied[0] == false && grpOccupied[2] == false) {
                maxGrps += 2;
            }
            // Only one of the Gropus 1, 2, and 3 can be booked
            else if (!grpOccupied[0] || !grpOccupied[1] || !grpOccupied[2]) {
                maxGrps += 1;
            }
        }
        return maxGrps;
    }
    */
};