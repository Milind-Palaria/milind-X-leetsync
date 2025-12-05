class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        for (int i = 0; i < nums.size()-1; i++) {
            int x = nums[i];
            int y = sum - x;
            if (abs(x - y) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};