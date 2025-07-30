class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result=0;
        int count=0;
        int max_num=nums[0];
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>max_num){
                max_num=nums[i];
                count=0;
                result=0;
            }
            if((max_num & nums[i]) == max_num){
                count++;
                result=max(result,count);
            }else{
                count=0;
            }
        }
        return result;
    }
};