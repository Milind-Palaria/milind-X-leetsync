class Solution {
public:
    static long long countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;

        unordered_map<int, long long> freq;
        freq.reserve(points.size());
        for (auto &p : points)
            freq[p[1]]++;

        long long sum = 0, c2 = 0;

        for (auto &[y, f] : freq) {
            if (f <= 1) continue;
            long long c = f * (f - 1LL) / 2LL;
            sum += c;
            c2 += c * c;
        }

        long long ans = (sum * sum - c2) / 2;
        ans %= MOD;
        if (ans < 0) ans += MOD;

        return ans;
    }
};