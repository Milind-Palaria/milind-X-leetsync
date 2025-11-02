class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(auto &x:g) grid[x[0]][x[1]]=1;
        for(auto &x:w) grid[x[0]][x[1]]=2;
        for(auto &x:g){
            int r=x[0],c=x[1];
            for(int i=r-1;i>=0&&grid[i][c]!=2&&grid[i][c]!=1;i--) if(!grid[i][c]) grid[i][c]=3;
            for(int i=r+1;i<m&&grid[i][c]!=2&&grid[i][c]!=1;i++) if(!grid[i][c]) grid[i][c]=3;
            for(int j=c-1;j>=0&&grid[r][j]!=2&&grid[r][j]!=1;j--) if(!grid[r][j]) grid[r][j]=3;
            for(int j=c+1;j<n&&grid[r][j]!=2&&grid[r][j]!=1;j++) if(!grid[r][j]) grid[r][j]=3;
        }
        int ans=0;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(!grid[i][j]) ans++;
        return ans;
    }
};