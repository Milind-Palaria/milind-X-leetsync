class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int maxWindowSize=0;
        int windowSize = 1;
        int preWindowSize=0;
        int ans = 1;
        int last = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                windowSize++;
                last = i;
                ans=max(ans,min(preWindowSize,windowSize));
            }else{
                if(i-last<=1) preWindowSize=windowSize;
                else preWindowSize=0;

                windowSize=1;
            }
            maxWindowSize=max(maxWindowSize,windowSize);
        }
        return ans>(maxWindowSize/2)?ans:maxWindowSize/2;
    }
};