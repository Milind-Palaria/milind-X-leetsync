class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // Calculate sums and count zeros
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;
        
        for (int num : nums1) {
            sum1 += num;
            zeros1 += (num == 0);
        }
        
        for (int num : nums2) {
            sum2 += num;
            zeros2 += (num == 0);
        }
        
        // Calculate minimum possible sum for each array
        long long minSum1 = sum1 + zeros1;
        long long minSum2 = sum2 + zeros2;
        
        // Case 1: If both arrays have zeros, we can make them equal
        if (zeros1 > 0 && zeros2 > 0) {
            return max(minSum1, minSum2);
        }
        
        // Case 2: If only the first array has zeros
        if (zeros1 > 0 && zeros2 == 0) {
            // Check if we can increase nums1 to match nums2
            return (minSum1 <= sum2) ? sum2 : -1;
        }
        
        // Case 3: If only the second array has zeros
        if (zeros1 == 0 && zeros2 > 0) {
            // Check if we can increase nums2 to match nums1
            return (minSum2 <= sum1) ? sum1 : -1;
        }
        
        // Case 4: Neither array has zeros
        return (sum1 == sum2) ? sum1 : -1;
    }
};