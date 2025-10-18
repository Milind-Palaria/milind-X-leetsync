class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = INT_MIN, res = 0;
        for (auto& x : nums) {
            int l = x - k, r = x + k;
            int p = max(last + 1, l);
            if (p <= r)
                res++;
            else
                p=last;    
            last = p;
        }
        return res;
    }
};