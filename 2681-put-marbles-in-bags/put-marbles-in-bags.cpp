class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || k == n) {
            return 0;
        }
        vector<long long> pairs;
        for (int i = 0; i < n - 1; ++i) {
            pairs.push_back(weights[i] + weights[i + 1]);
        }
        sort(pairs.begin(), pairs.end());
        long long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; ++i) {
            minScore += pairs[i];
            maxScore += pairs[n - 2 - i];
        }
        return maxScore - minScore;
    }
};