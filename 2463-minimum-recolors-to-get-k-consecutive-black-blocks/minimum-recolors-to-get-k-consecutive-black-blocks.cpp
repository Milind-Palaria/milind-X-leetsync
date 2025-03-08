class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=0;
        int ans=INT_MAX;
        int whites=0;
        while(j!=blocks.length()){
            if(blocks[j]=='W')whites++;
            if(j-i+1>=k){
                ans=min(ans,whites);
                if(blocks[i]=='W')whites--;
                i++;
            }
            j++;
        }
        return ans;
    }
};