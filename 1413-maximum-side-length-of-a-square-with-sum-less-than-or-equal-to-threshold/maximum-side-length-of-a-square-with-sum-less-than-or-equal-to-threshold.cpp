class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for(int row = 1; row <= m; ++row){
            for(int col = 1; col <= n; ++col){
                prefix[row][col] = mat[row - 1][col - 1] 
                                 + prefix[row - 1][col]
                                 + prefix[row][col - 1]
                                 - prefix[row - 1][col - 1];
            }
        }

        int low = 0, high = min(m, n), ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;
            bool ok = false;

            for(int i = mid; i <= m; i++){
                for(int j = mid; j <= n; j++){
                    int sum = prefix[i][j]
                            - prefix[i-mid][j]
                            - prefix[i][j-mid]
                            + prefix[i-mid][j-mid];
                    if(sum <= threshold){
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }

            if(ok){
                ans = mid;      
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};