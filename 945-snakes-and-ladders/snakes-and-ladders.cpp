class Solution {
public:
    int getShortestBFS(const vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            if (curr == n * n)
                return moves;
            for (int i = 1; i <= 6 && curr + i <= n * n; ++i) {
                int next = curr + i;
                int boardVal = getBoardValue(board, next, n);
                if (boardVal != -1)
                    next = boardVal;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }

    int getBoardValue(const vector<vector<int>>& board, int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        int row = n - 1 - r;
        int col = (r % 2 == 0) ? c : (n - 1 - c);
        return board[row][col];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        return getShortestBFS(board);
    }
};