class Solution {
public:
    long long maxSubarraySum(vector<int>& a, int k) {
        long long inf=1e18;
        long long ans=-inf;
        int n=a.size();
        vector<long long> dp(n),pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        for(int i=0;i<n;i++){
            long long last=pre[i]-(i-k>=0?pre[i-k]:inf);
            if(i-k==-1) last=pre[i];
            dp[i]=max(last,last+(i-k>=0?dp[i-k]:0));
            ans=max(ans,dp[i]);
        }
        return ans;

    }
};