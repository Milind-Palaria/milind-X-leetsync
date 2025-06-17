class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=-1;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mini)
            {
                mini=nums[i];
            }
            else if(nums[i]>mini)
            {
                maxi=max(maxi,nums[i]-mini);
            }
        }
        return maxi;
    }
};