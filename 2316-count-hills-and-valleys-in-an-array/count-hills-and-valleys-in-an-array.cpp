class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int cnt = 0, n = nums.size();

        for(int i = 1; i < n - 1; i++){
            
            if(i == 0 || i == n) continue;
            
            if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
                cnt++;
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                cnt++;
            if(nums[i] == nums[i + 1])
                nums[i] = nums[i - 1];
            
        }
        
        return cnt;
    }
};