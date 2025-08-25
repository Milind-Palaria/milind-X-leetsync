class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int>ans;
        bool f = true;
        int i=0,j=0;
        while(i!=row-1 or j!=col-1)
        {
            if(f)
            {
                while(i>=0 and j<col)
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                i++;j--;
                if(j<col-1)j++;
                else i++;
                f = false;
            }
            else
            {
                while(i<row and j>=0)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--;j++;
                if(i<row-1) i++;
                else j++;
                f = true;
            }
        }
        ans.push_back(mat[i][j]);
        return ans;

    }
};