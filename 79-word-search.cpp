class Solution {
public:
    bool searchUsingDFS(int row, int col, vector<vector<char>>& board, int ind,
                        string word) {
        int n = board.size(), m = board[0].size(), wordLen = word.size();
        if (ind == wordLen) {
            return true;
        }
        if (row < 0 || col < 0 || row >= n || col >= m ||
            board[row][col] != word[ind]) {
            return false;
        }
        char originalChar = board[row][col];
        board[row][col] = '#';

        bool charFound = searchUsingDFS(row + 1, col, board, ind + 1, word) ||
                         searchUsingDFS(row - 1, col, board, ind + 1, word) ||
                         searchUsingDFS(row, col + 1, board, ind + 1, word) ||
                         searchUsingDFS(row, col - 1, board, ind + 1, word);

        board[row][col] = originalChar;
        return charFound;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size(), m = board[0].size(), wordLen = word.size();
        if (wordLen > n * m) {
            return false;
        }
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (board[row][col] != word[0]) {
                    continue;
                }
                if (searchUsingDFS(row, col, board, 0, word) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};