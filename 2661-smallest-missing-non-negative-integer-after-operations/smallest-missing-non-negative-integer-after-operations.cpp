class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> count(value, 0);
        for (auto& x : nums) {
            int r = ((x % value) + value) % value;
            count[r]++;
        }
        for (int i = 0; i < n; i++) {
            int r = (i % value);
            if (count[r] == 0)
                return i;
            count[r]--;
        }
        return n;
    }
};