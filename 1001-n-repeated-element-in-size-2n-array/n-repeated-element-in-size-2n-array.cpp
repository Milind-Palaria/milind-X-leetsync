class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n-1;i+=2){
            if(nums[i]==nums[i+1]) return nums[i];
        }

        if(nums[0]==nums[2] or nums[0]==nums[3]) return nums[0];
        return nums[1];
    }
};