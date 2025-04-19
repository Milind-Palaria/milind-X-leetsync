class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int x = lower - nums[i];
            int y = upper - nums[i];
            int idxlow =
                lower_bound(nums.begin() + i + 1, nums.end(), x) - nums.begin();
            int idxup =
                upper_bound(nums.begin() + i + 1, nums.end(), y) - nums.begin();

            int val = idxup - idxlow;
            ans += val;
        }
        return ans;
    }
};