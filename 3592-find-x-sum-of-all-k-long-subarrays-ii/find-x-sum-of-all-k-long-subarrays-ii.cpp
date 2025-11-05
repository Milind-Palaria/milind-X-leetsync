class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;
        multiset<pair<int, int>> hi, lo;
        long long sum = 0;

        auto update = [&](int val, int delta) {
            pair<int, int> smallest = *(hi.begin());
            pair<int, int> p = make_pair(mp[val], val);
            if(p >= smallest) {
                sum -= (1ll * val * mp[val]);
                hi.erase(p);
            } else lo.erase(p);

            mp[val] += delta;
            p = make_pair(mp[val], val);

            if(hi.size() < x) {
                if(lo.size() && *(lo.rbegin()) > p) {
                    pair<int, int> largest = *(lo.rbegin());
                    hi.insert(largest);
                    lo.erase(largest);
                    lo.insert(p);

                    sum += (1ll * largest.first * largest.second);

                } else {
                    hi.insert(p);
                    sum += (1ll * p.first * p.second);
                } 
            } else {
                if(p > smallest) {
                    hi.insert(p);
                    lo.insert(smallest);
                    hi.erase(smallest);

                    sum -= (1ll * smallest.first * smallest.second);
                    sum += (1ll * p.first * p.second);

                } else lo.insert(p);
            }
        };

        int l = 0;
        vector<long long> ans;
        for(int r = 0; r < nums.size(); r++) {
            update(nums[r], 1);
            if(r-l+1 > k) update(nums[l++], -1);
            if(r-l+1 == k) ans.push_back(sum);
        }

        return ans;
    }
};