class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        vector<int> dp(n, 1), pre(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
        }

        vector<int> ans;
        int idx = -1, maxx = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxx) {
                maxx = dp[i];
                idx = i;
            }
        }

        ans.push_back(nums[idx]);
        while (pre[idx] != -1) {
            idx = pre[idx];
            ans.push_back(nums[idx]);
        }

        return ans;
    }
};