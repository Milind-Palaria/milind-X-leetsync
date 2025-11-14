class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
       vector<vector<int>>hash(n,vector<int>(n,0));
       for(auto it: queries){
        int r1=it[0], c1=it[1],r2=it[2],c2=it[3];
         if( (c2+1)<n) hash[r1][c2+1]--;
         if((r2+1)<n)  hash[r2+1][c1]--;
         if((r2+1)<n && (c2+1)<n) hash[r2+1][c2+1]++;
         hash[r1][c1]++;
       }
       for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            hash[i][j]+=hash[i][j-1];
        }
       }
       for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            hash[i][j]+=hash[i-1][j];
        }
       }
       return hash;
    }
};