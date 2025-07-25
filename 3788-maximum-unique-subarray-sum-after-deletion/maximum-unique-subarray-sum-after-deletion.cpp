class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        unordered_set<int> uniqueNum;
        int maxSum = nums[0];
        uniqueNum.insert(nums[0]);
        for(int i: nums){
            if(uniqueNum.count(i) != 1){
                uniqueNum.insert(i);
                maxSum = max({maxSum, maxSum + i, i});
            }
        }
        return maxSum;
    }
};