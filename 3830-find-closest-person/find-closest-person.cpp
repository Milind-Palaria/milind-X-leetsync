class Solution {
public:
    int findClosest(int x, int y, int z) {
       int dist_x=abs(z-x);
       int dist_y=abs(z-y);
       if(dist_x==dist_y) return 0;
       return(dist_x<dist_y)?1:2; 
    }
};