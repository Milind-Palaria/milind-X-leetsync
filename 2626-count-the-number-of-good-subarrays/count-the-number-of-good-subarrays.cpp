#define ll long long int
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll ans = 0; // Stores the total count of good subarrays
        int n = nums.size();
        unordered_map<int, int> mp; // Tracks frequency of elements in the current window
        int low = 0, high = 0; // Sliding window pointers
        
        while (high < n and low <= high) {
            // For each new element, add its existing frequency to the pair count (k)
            k -= mp[nums[high]]++; // Each occurrence before 'high' forms a new pair
            ++high; // Expand the window
            
            // While the window has at least 'k' pairs (k <= 0)
            while (low <= high and k <= 0) {
                // Remove the leftmost element and adjust pair count
                k += --mp[nums[low++]];
            }
            
            // All subarrays from [0...low-1] to [high-1] are valid
            ans += 1ll * low;
        }

        return ans;
    }
};