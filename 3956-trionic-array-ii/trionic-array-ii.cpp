class Solution {
public:
    long long dp[100009][4][2];
    bool vis[100009][4][2];
    long long solve(int i, int j, int k, vector<int>& a) {
        if (i == a.size()) return j == 3? 0:-1e14;

        long long &ans=dp[i][j][k];
        if (vis[i][j][k]) return ans;
        vis[i][j][k]=true;
        ans=-1e14;

        if (!j) {
            ans=max(solve(i+1, j, k, a), solve(i+1, 1, 0, a)+a[i]);
        } else if (j == 1) {
            if (a[i] > a[i-1]) {
                ans=solve(i+1, 1, 1, a)+a[i];
            } else if (a[i] < a[i-1] && k) {
                ans=solve(i+1, 2, 1, a)+a[i];
            }
        } else if (j == 2) {
            if (a[i] < a[i-1]) {
                ans=solve(i+1, 2, 1, a)+a[i];
            } else if (a[i] > a[i-1]) {
                ans=solve(i+1, 3, 1, a)+a[i];
            }
        } else {
            ans=0;
            if (a[i] > a[i-1]) {
                ans=max(solve(i+1, 3, 1, a)+a[i], ans);
            }
        }

        return ans;
    }
    long long maxSumTrionic(vector<int>& nums) {
        memset(vis, false, sizeof vis);
        return solve(0, 0, 1, nums);
    }
};