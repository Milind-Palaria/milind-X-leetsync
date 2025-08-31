class Solution {
public:
    bool canPlace(char ch, int row, int col, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int j = 0; j < m; j++) {
            if (board[row][j] == ch)
                return false;
        }
        for (int i = 0; i < n; i++) {
            if (board[i][col] == ch)
                return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }
    bool f(int row, int col, vector<vector<char>>& board) {
        if (row >= board.size())
            return true;
        if (col >= board[0].size())
           return f(row + 1, 0, board);
        if (board[row][col] != '.') {
            return f(row, col + 1, board);
        } else {
            for (char ch = '1'; ch <= '9'; ch++) {
                if (canPlace(ch, row, col, board)) {
                    board[row][col] = ch;
                    if(f(row, col + 1, board))
                    return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        f(0,0,board);
    }
};