class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minH=INT_MAX;
        int maxH=INT_MIN;
        int minW=INT_MAX;
        int maxW=INT_MIN;
        bool check = true;

        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==1){
                    check=false;
                    minH=min(minH, i);
                    maxH=max(maxH, i);
                    minW=min(minW, j);
                    maxW=max(maxW, j);
                }
            }
        }

        if(check) return 0;

        return (maxH - minH + 1) * (maxW - minW + 1);
    }
};