class Solution {
public:
int MOD=1e9+7;
    int numSub(string s) {
        int n=s.size();
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                count++;
                ans= (ans%MOD +count%MOD)%MOD;
            }
            else{
                count=0;
            }
        }
        return ans;
    }
};