class Solution {
public:
    int findMinArea(int stX, int stY, int enX, int enY, vector<vector<int>>& grid) {
        int maxX = -1, minX = 1000, maxY = -1, minY = 1000;
        for (int i = stX; i <= enX; i++) {
            for (int j = stY; j <= enY; j++) {
                if (grid[i][j] == 1) {
                    minX = min(i, minX);
                    minY = min(j, minY);
                    maxX = max(i, maxX);
                    maxY = max(j, maxY);
                }
            }
        }

        if (maxX == -1) return -1;
        return (maxX - minX + 1) * (maxY - minY + 1);
    }

    int findMinAreaRects(int stX, int stY, int enX, int enY, vector<vector<int>>& grid, bool isRecurrence = false) {
        int minArea = 1000;
        for (int i = stX; i < enX; i++) {
            int minAreaBeforePartition = findMinArea(stX, stY, i, enY, grid);
            int minAreaAfterPartition = findMinArea(i + 1, stY, enX, enY, grid);

            if (minAreaBeforePartition == -1 || minAreaAfterPartition == -1) continue;
            
            if (!isRecurrence) {
                int op1 = findMinAreaRects(stX, stY, 
                                          i, enY, grid, true) + 
                                          minAreaAfterPartition;

                int op2 = findMinAreaRects(i + 1, stY, 
                                          enX, enY, grid, true) + 
                                          minAreaBeforePartition;
                minArea = min(min(op1, op2), minArea);
            } else {
                minArea = min(minAreaBeforePartition + minAreaAfterPartition, minArea);
            }
        }

        for (int j = stY; j < enY; j++) {
            int minAreaBeforePartition = findMinArea(stX, stY, enX, j, grid);
            int minAreaAfterPartition = findMinArea(stX, j + 1, enX, enY, grid);

            if (minAreaBeforePartition == -1 || minAreaAfterPartition == -1) continue;

            if (!isRecurrence) {
                int op1 = findMinAreaRects(stX, stY, 
                                          enX, j, grid, true) + 
                                          minAreaAfterPartition;

                int op2 = findMinAreaRects(stX, j + 1, 
                                          enX, enY, grid, true) + 
                                          minAreaBeforePartition;
                minArea = min(min(op1, op2), minArea);    
            } else {
                minArea = min(minAreaBeforePartition + minAreaAfterPartition, minArea);
            }
        }

        return minArea;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        return findMinAreaRects(0, 0, n - 1, m - 1, grid);
    }
};