class Solution {
public:
    int checkCorners(vector<vector<int>>& grid, int i, int j) {
        if(grid[i-1][j-1] % 2==0 && 
            grid[i+1][j+1] % 2 == 0 && 
            grid[i+1][j-1] % 2 == 0 && 
            grid[i-1][j+1] % 2 == 0) return true;

        return false;
    }

    int checkMagicSquare(vector<vector<int>>& grid, int i, int j) {
        int top = grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1];
        int left = grid[i-1][j-1] + grid[i][j-1] + grid[i+1][j-1];
        int right = grid[i-1][j+1] + grid[i][j+1] + grid[i+1][j+1];
        int bottom = grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
        int horizontal = grid[i][j-1] + grid[i][j] + grid[i][j+1];
        int vertical = grid[i-1][j] + grid[i][j] + grid[i+1][j];

        if(top == 15 && left == 15 && right == 15 && bottom == 15 && horizontal == 15 && vertical == 15) return 1;
        return 0;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;

        for(int i = 1;i<grid.size()-1;i++) {
            for(int j = 1;j<grid[0].size()-1;j++) {
                if(grid[i][j] == 5 && checkCorners(grid,i,j)) {
                    res+=checkMagicSquare(grid,i,j);
                }
            }
        }
        return res;
    }
};