class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.back().size();    
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n));

        for (int i = 0; i < m; i++) {
            dp[n - 1][i] = triangle.back()[i];
        }    

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
               
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0]; 
    }
};