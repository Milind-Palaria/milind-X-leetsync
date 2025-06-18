class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n; i += 3) {
        vector<int> group = {nums[i], nums[i+1], nums[i+2]};
        if (group[2] - group[0] > k) {
            return {};
        }
        res.push_back(group);
    }
    return res;
    }
};