class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        using ll = long long;
        ll maxSum = 0;
        ll minEle = INT_MAX;
        int numNeg = 0;
        for(auto & row: matrix){
            for(auto& i: row){
                minEle = min(llabs(i), minEle);
                maxSum += abs(i);
                if (i < 0) numNeg++;
            }
        }
        return maxSum-((numNeg%2==0)?0:2*minEle);
    }
};