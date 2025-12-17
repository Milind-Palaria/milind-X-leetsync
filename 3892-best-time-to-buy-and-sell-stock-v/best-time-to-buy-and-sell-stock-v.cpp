#define ll long long
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        ll n = prices.size();      
        vector<vector<ll>> dp(n, vector<ll>(k+1,0));

        for(ll j=1; j<=k; j++){
                ll bestprevbuy = dp[0][j-1] - prices[0];
                ll bestprevsell = dp[0][j-1] + prices[0];
            for(ll i=1;i<n;i++){
                dp[i][j] = max(dp[i-1][j], bestprevbuy + prices[i]);
                bestprevbuy = max(bestprevbuy, dp[i-1][j-1] - prices[i]);
                dp[i][j] = max({dp[i][j], dp[i-1][j], bestprevsell - prices[i]});
                bestprevsell = max(bestprevsell, dp[i-1][j-1] + prices[i]);
            }
        }   
        return dp[n-1][k];
    }
};