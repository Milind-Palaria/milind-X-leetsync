#define ll long long
class Solution {
public:
    ll removedSubarryLen(vector<int> nums, int p) {
        ll n = nums.size(), sum = 0, res = INT_MAX, currMod, reqMod, size;
        vector<ll> v(n, 0ll);
        unordered_map<ll, vector<ll>> mp;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            v[i] = sum;
            mp[sum % p].push_back(i);
        }

        if (sum % p == 0)
            return 0;

        for (int i = (n - 1); i >= 1; i--) {
            currMod = (v[n - 1] - v[i - 1]) % p;
            mp[v[i] % p].pop_back();

            if (currMod != 0)
                reqMod = (p - currMod);
            else
                reqMod = 0;

            size = mp[reqMod].size();

            if (size != 0)
                res = min(res, (i - mp[reqMod][size - 1] - 1));
            else if (currMod == 0)
                res = min(res, (n - (n - i)));
        }
        return res;
    }

    int minSubarray(vector<int>& nums, int p) {
        ll res = removedSubarryLen(nums, p);
        reverse(nums.begin(), nums.end());
        res = min(res, removedSubarryLen(nums, p));

        return res == INT_MAX ? -1 : res;
    }
};