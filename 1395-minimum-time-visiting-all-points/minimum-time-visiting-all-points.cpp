class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_time=0;
        for(int i=0;i<n-1;i++){
            int xi=points[i][0];
            int xj=points[i+1][0];
            int yi=points[i][1];
            int yj=points[i+1][1];
        
            int time = max(abs(xj-xi),abs(yj-yi));
            
            min_time += time;
        }
        return min_time;
    }
};