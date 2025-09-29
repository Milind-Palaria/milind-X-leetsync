#define INT_MAX 100000007
class Solution {
public:
    int dp[51][51];
    int recurs(vector<int>& values, int i, int j) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int x = i; x < j; x++)
            ans = min(ans, (values[j] * values[i - 1] * values[x]) +
                               recurs(values, x + 1, j) + recurs(values, i, x));

        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return recurs(values, 1, n - 1);
    }
};