class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n=grid.size();
       int size=n*n;
       vector<int> count(size+1,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            count[grid[i][j]]++;
        }
       }
       int twice=-1,missing=-1;
       for(int num=1;num<=size;num++){
        if(count[num]==2) twice=num;
        if(count[num]==0) missing=num;
       }
              return {twice,missing};
       } 

    
};