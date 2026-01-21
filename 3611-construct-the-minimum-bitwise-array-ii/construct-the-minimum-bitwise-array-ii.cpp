class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==2)ans[i]=-1;
            else 
            {
                for(int j=0;j<31;j++)
                {
                    int num = (1<<j);
                    
                    if((nums[i]&num) == 0)
                    {
                        int res = nums[i]^(1<<(j-1));
                        ans[i]=res;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};