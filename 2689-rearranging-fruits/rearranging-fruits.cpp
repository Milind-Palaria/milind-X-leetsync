class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        long long sum1 = accumulate(basket1.begin(), basket1.end(), 0LL),
                  sum2 = accumulate(basket2.begin(), basket2.end(), 0LL);
        if ((sum1 + sum2) % 2 == 1) {
            return -1;
        }
        long long minFruit = LLONG_MAX;
        map<int, int> mp1, mp2;
        map<int, int> tot;
        for (int i = 0; i < n; i++) {
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
            minFruit = min({minFruit, (long long)basket1[i], (long long)basket2[i]});
        }
        for (auto& i : mp1)
            tot[i.first] += i.second;
        for (auto& i : mp2)
            tot[i.first] += i.second;
        for (auto& i : tot)
            if (i.second % 2)
                return -1;
        vector<int> swapped1, swapped2;
        for (auto& i : tot) {
            int total = i.second;
            int val = i.first;
            int freq1 = mp1[val];
            int freq2 = mp2[val];
            int target = total / 2;
            if (freq1 > target) {
                for (int j = 0; j < freq1 - target; ++j)
                    swapped1.push_back(val);
            } else if (freq2 > target) {
                for (int j = 0; j < freq2 - target; ++j)
                    swapped2.push_back(val);
            }
        }
        sort(swapped1.begin(), swapped1.end());
        sort(swapped2.rbegin(), swapped2.rend());
        long long minCost = 0;
        for (int l = 0; l < swapped1.size(); ++l) {
            minCost += min({(long long)swapped1[l], (long long)swapped2[l], 2LL * minFruit});
        }
        return minCost;
    }
};