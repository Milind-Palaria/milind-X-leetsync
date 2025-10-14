class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size()-2*k+1;i++) {
            int ptr1=i+1, ptr2=i+k+1, cntr;
            bool arr1=true, arr2=true;
            
            cntr=k;
            while(ptr1<nums.size() && --cntr>0) {
                if(nums[ptr1]<=nums[ptr1-1]) {
                    arr1=false;
                    break;
                }
                ptr1++;
            }

            cntr=k;
            while(ptr2<nums.size() && --cntr>0) {
                if(nums[ptr2]<=nums[ptr2-1]) {
                    arr2=false;
                    break;
                }
                ptr2++;
            }
            
            if(arr1 && arr2) return true;
        }
        return false;
    }
};