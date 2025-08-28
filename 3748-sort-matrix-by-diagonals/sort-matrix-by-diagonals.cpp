class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        int i = n - 1;
        int j = 0;

        while (j < ((2 * n) - 1)) {
            vector<int> diag;
            if (j < n) {
                int l = i;
                for (int k = 0; k <= j && (l<n); k++) {
                    diag.push_back(grid[l][k]);
                    l++;
                }
                sort(diag.begin(), diag.end());
                l = i;
                for (int k = 0; k <= j && (l<n); k++) {

                    grid[l][k] = diag.back();
                    diag.pop_back();
                    l++;
                }
            } else {
                int l = 0;
                for (int c = (j - (n - 1)); c < n; c++) {

                    diag.push_back(grid[l][c]);
                    l++;
                }
                sort(diag.begin(), diag.end(), greater<int>());
                l = 0;
                for (int c = (j - (n - 1)); c < n; c++) {

                    grid[l][c] = diag.back();
                    diag.pop_back();
                    l++;
                }
            }

            i--;
            j++;
        }

        return grid;
    }
};