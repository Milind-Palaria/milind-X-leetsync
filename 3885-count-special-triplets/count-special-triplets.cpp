class Solution {
public:
    using ll = long long;
    int mod = 1000000007;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> total;
        unordered_map<int, int> prefix;
        for (auto& x : nums)
            total[x]++;
        ll res = 0;
        for (auto& x : nums) {
            int dx = 2 * x;
            total[x]--;
            ll before = prefix[dx];
            ll after = total[dx];
            res = (res + (before * after) % mod) % mod;
            prefix[x]++;
        }
        return res;
    }
};