class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = 0;
        for (int i : candies) {
            total_candies += i;
        }
        
        if (total_candies < k) return 0;

        long long left = 1, right = *max_element(candies.begin(), candies.end());
        
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            long long total = 0;

            for (int i : candies) {
                total += i / mid;
            }

            if (total >= k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};