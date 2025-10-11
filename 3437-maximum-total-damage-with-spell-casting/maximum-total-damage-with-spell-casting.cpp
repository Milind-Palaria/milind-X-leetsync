class Solution {
public:

    long long int solve(vector<int> &v, int n, map<int,int> &mp,int i,vector<long long int> &dp){

        if(i>=n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        long long int nt= solve(v,n,mp,i+1,dp);

        long long int t;

        t=1ll*v[i]*mp[v[i]];

        if(i+1<n && v[i+1]-1!=v[i] && v[i+1]-2!=v[i])
        t+=solve(v,n,mp,i+1,dp);
        else if(i+2<n && v[i+2]-2!=v[i])
        t+=solve(v,n,mp,i+2,dp);
        else
        t+=solve(v,n,mp,i+3,dp);

        return dp[i]=max(t,nt);
        

    }
    long long maximumTotalDamage(vector<int>& power) {
        
        map<int,int> mp;

        int n=power.size();

        for(int i=0;i<n;i++)
        mp[power[i]]++;

        vector<int> v;

        for(auto it: mp)
        v.push_back(it.first);

        vector<long long int> dp(v.size(),-1);

        return solve(v,v.size(),mp,0,dp);
    }
};