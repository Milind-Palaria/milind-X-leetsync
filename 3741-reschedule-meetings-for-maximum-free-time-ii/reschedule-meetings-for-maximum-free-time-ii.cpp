#define vi vector<int>
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vi gaps;
        int ans = startTime[0]; // Initial gap before the first meeting
        gaps.push_back(startTime[0]);
        
        // Compute gaps between meetings and after the last meeting
        for (int i = 1; i <= n; ++i) {
            int diff = (i == n ? eventTime : startTime[i]) - endTime[i - 1];
            gaps.push_back(diff);
            ans = max(ans, diff); // Track the largest gap initially
        }

        // Precompute the maximum gap to the right of each position
        int m = gaps.size();
        vector<int> rightMaxGap(m, 0);
        for (int i = m - 2; i >= 0; --i) {
            rightMaxGap[i] = max(rightMaxGap[i + 1], gaps[i + 1]);
        }

        int leftMaxGap = 0; // Tracks the maximum gap to the left dynamically
        for (int i = 1; i < m; ++i) {
            int currGap = endTime[i - 1] - startTime[i - 1]; // Duration of the current meeting
            int canBe = gaps[i - 1] + gaps[i] + currGap; // Potential new gap if meeting is moved
            
            // If the meeting can fit in either left or right max gap, update answer
            if (currGap <= max(leftMaxGap, rightMaxGap[i]))
                ans = max(ans, canBe);

            // Special case: If moving the meeting is not possible, merge adjacent gaps
            ans = max(ans, gaps[i-1] + gaps[i]);

            leftMaxGap = max(leftMaxGap, gaps[i - 1]); // Update leftMaxGap for next iteration
        }
        return ans;
    }
};