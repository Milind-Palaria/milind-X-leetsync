class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        ranges::sort(nums);
        int result = 1;
        for (int i = 0, start = 0, end = 0, curr = 0; i < nums.size();) {
            int pos = min(nums[i], nums[end] + k + 1);
            if (start < nums.size()) pos = min(pos, nums[start] - k);

            int free = 0;
            while (i < nums.size() and nums[i] == pos) i++, free++;
            while (start < nums.size() and nums[start] - k == pos)  curr++, start++;
            while (nums[end] + k + 1 == pos) curr--, end++;
            result = max(result, free + min(curr - free, numOperations));
        }
        return result;
    }
};