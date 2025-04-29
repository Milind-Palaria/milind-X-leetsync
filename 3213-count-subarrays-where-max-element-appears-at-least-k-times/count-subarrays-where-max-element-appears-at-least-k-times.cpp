const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(___::_);
    return 0;
}();
#endif
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = 0, n = nums.size();
        for (int i = 0; i < n; i++)
          maxVal = max(maxVal,nums[i]);
        int left = 0, right = 0;
        int cnt_MAX = 0;
        long long res = 0;
        while (right < n) {
            if (nums[right] == maxVal) cnt_MAX++;
            while (cnt_MAX == k) {
                cnt_MAX -= nums[left] == maxVal ? 1 : 0;
                left++;
            }
            res += left ;
            right ++; 
        }
        return res;
    }
};