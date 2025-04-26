class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int left = 0;       // Start of valid window
        int lastMin = -1, lastMax = -1, lastInvalid = -1;

        for(int i=0;i<nums.size();i++)
        {
            // If the current element is out of valid range
            if(nums[i] < minK || nums[i] > maxK)
            {
                lastInvalid = i;
            } 

            if(nums[i] == minK)
            {
                lastMin = i;
            }

            if(nums[i] == maxK)
            {
                lastMax = i;
            }

            // Minimum index where both mink and maxk are included
            int minBound = min(lastMin, lastMax);

            // If both mink and maxk have been seen in valid range
            if(minBound > lastInvalid)
            {
                result += minBound - lastInvalid;
            }
        }

        return result;
    }
};