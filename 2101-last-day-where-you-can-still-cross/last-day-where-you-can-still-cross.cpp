class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lastDay = 0;

        vector<pair<int, int>> directions = {{1,0}, {0,1}, {0,-1}, {-1,0}};

        function<bool(int)> walkDown = [&] (int day)
        {
            vector<vector<bool>> flooded(row, vector(col, false));;
            for (int i{}; i <= day; ++i) 
            {
                flooded[cells[i][0]-1][cells[i][1]-1] = true;
            }
            queue<pair<int,int>> q;
            vector<vector<bool>> visited(row, vector<bool>(col, false));

            for (int c{}; c < col; ++c) 
            {
                if (!flooded[0][c]) 
                {
                    q.push({0, c});
                    visited[0][c] = true;
                }
            }
            while(!q.empty())
            {
                auto [r, c] = q.front(); q.pop();
                if (r == row - 1) return true;
                for(auto d : directions)
                {
                    int nextR = r + d.first, nextC = c + d.second;  
                    if(nextR >= row || nextC >= col || nextR < 0 || nextC < 0 ) continue;
                    if(flooded[nextR][nextC] || visited[nextR][nextC])  continue;
                    visited[nextR][nextC] = true;
                    q.push({nextR, nextC});
                }
            }
            return false;
        };


        int l=0, h=cells.size()-1;
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(walkDown(mid))
            { 
                l = mid+1;
            }
            else h = mid-1; 
        }

        return l;
    }
};