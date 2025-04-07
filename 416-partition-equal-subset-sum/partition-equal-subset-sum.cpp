class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =
            accumulate(nums.begin(), nums.end(), 0); // Calculate total sum
        if (sum % 2 == 1) // If sum is odd, partition is impossible
            return false;
        int target = sum / 2;               // Target sum for each subset
        vector<bool> dp(target + 1, false); // DP array to track reachable sums
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) { // Traverse DP array backwards
                dp[j] = dp[j] || dp[j - num];     // Update reachable sums
            }
        }
        return dp[target]; // Start recursion
    }
};