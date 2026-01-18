class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();          // rows
        int n = grid[0].size();       // columns

        vector<vector<int>> row_prefsum(m, vector<int>(n));
        vector<vector<int>> col_prefsum(m, vector<int>(n));

        // row prefix sum
        for (int i = 0; i < m; i++) {
            row_prefsum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                row_prefsum[i][j] = row_prefsum[i][j - 1] + grid[i][j];
            }
        }

        // column prefix sum
        for (int j = 0; j < n; j++) {
            col_prefsum[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                col_prefsum[i][j] = col_prefsum[i - 1][j] + grid[i][j];
            }
        }

        // trying all max sides greedily
        for (int side = min(m, n); side > 1; side--) {

            for (int i = 0; i + side - 1 < m; i++) {

                for (int j = 0; j + side - 1 < n; j++) {

                    int target = row_prefsum[i][j + side - 1]
                               - (j > 0 ? row_prefsum[i][j - 1] : 0);

                    bool different = false;

                    // rows check
                    for (int row = i + 1; row < i + side; row++) {
                        int sum = row_prefsum[row][j + side - 1]
                                - (j > 0 ? row_prefsum[row][j - 1] : 0);
                        if (sum != target) {
                            different = true;
                            break;
                        }
                    }

                    if (different) continue;

                    // columns check
                    for (int col = j; col < j + side; col++) {
                        int sum = col_prefsum[i + side - 1][col]
                                - (i > 0 ? col_prefsum[i - 1][col] : 0);
                        if (sum != target) {
                            different = true;
                            break;
                        }
                    }

                    if (different) continue;

                    // diagonal and anti-diagonal
                    int diagonal = 0, anti = 0;
                    for (int k = 0; k < side; k++) {
                        diagonal += grid[i + k][j + k];
                        anti += grid[i + k][j + side - 1 - k];
                    }

                    if (diagonal == target && anti == target)
                        return side;
                }
            }
        }

        return 1;
    }
};