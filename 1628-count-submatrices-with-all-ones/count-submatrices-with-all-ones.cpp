class Solution {
public:
    int oneDArrayCount(vector<int> &arr) {
        int cons = 0;
        int subCount = 0;

        for(int &val : arr) {
            if(val == 0) {
                cons = 0;
            }
            else {
                cons++;
            }

            subCount += cons;
        }

        return subCount;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;

        for(int sRow = 0; sRow < m; sRow++) {
            vector<int> arr(n, 1);

            for(int eRow = sRow; eRow < m; eRow++) {

                for(int col = 0; col < n; col++) {
                    arr[col] = arr[col] & mat[eRow][col];
                }

                ans += oneDArrayCount(arr);
            }
        }

        return ans;
    }
};