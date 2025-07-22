class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         unordered_map<int, int> freq;
        int l = 0, score = 0, maxi = 0;

        for (int r = 0; r < nums.size(); ++r) {
            score += nums[r];
            freq[nums[r]]++;

            while (l < r && freq[nums[r]] > 1) {
                freq[nums[l]]--;
                score -= nums[l];
                l++;
            }

            maxi = max(maxi, score);
        }

        return maxi;
    }
};