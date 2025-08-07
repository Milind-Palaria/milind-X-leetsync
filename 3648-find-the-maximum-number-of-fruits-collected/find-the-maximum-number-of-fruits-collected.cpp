class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& A) {

        int n = A.size();

        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = A[0][0]; dp[n - 1][0] = A[n - 1][0]; dp[0][n - 1] = A[0][n - 1];

        for (int i = 1; i < n - 1; ++i) {
            for (int j = n - 1; n - j <= i + 1; --j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
                if (j + 1 < n) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                dp[i][j] += A[i][j];
            }
        }

        for (int j = 1; j < n - 1; ++j) {
            for (int i = n - 1; n - i <= j + 1; --i) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]);
                if (i + 1 < n) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
                dp[i][j] += A[i][j];
            }
        }

        int res = 0;

        for (int i = 0; i < n; ++i) res += A[i][i];

        return res + dp[n - 1][n - 2] + dp[n - 2][n - 1];


    }
};