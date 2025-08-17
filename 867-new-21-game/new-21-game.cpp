class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts){
            return 1.0;
        }
        vector<double>dp(n+1);
        dp[0]=1;
        double sub=1;
        for(int i=1;i<=n;i++){
            dp[i]=sub/maxPts;
            if(i<k){
                sub+=dp[i];
            }
            if(i>=maxPts && i-maxPts<k){
                sub-=dp[i-maxPts];
            }
        }
        double ans=0;
        for(int i=k;i<=n;i++){
            ans+=dp[i];
        }
        return ans;
    }
};