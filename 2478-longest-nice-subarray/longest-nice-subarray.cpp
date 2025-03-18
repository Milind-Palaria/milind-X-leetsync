class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int j=0;
        int i=0;
        int ans=1;
        int mask=0;
        int n=nums.size();
        while(j<n){
            while((mask&nums[j])!=0){
                mask^=nums[i]; //removing the shrinked elemts from the mask
                i++;//  srinking the window 
            }
            ans=max(ans,j-i+1);
            mask|=nums[j];
            j++;

        }
        return ans; 
    }
};