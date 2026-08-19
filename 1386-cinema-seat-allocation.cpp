class Solution {
public:
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
            // Group 1 and Group 2 can be booked
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
};