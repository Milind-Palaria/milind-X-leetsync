class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for(int it : nums){
            if(it % 3 != 0) result++;
        }
        return result;
    }
};