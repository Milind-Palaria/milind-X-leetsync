class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n,0);
        vector<int> postsum(n,0);
        presum[0] = nums[0];
        postsum[n-1] = nums[n-1]; 
        for (int i=1;i<n;i++) presum[i] = max(presum[i-1],nums[i]);
        for (int i=n-2;i>=0;i--) postsum[i] = max(postsum[i+1],nums[i]);

        long long ans = 0;
        for (int j = 1;j<n-1;j++)
        {
            ans = max(ans,(long long)(presum[j-1] - nums[j]) * postsum[j+1]);
        }
        return ans;
    }
};