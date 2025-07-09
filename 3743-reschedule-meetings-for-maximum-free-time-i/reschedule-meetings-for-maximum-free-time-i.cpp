class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int>gap(n+1, 0);
        gap[0] = startTime[0];
        gap[n] = eventTime - endTime[n - 1];
        for(int i = 1; i < n; i++){
            gap[i] = startTime[i] - endTime[i -1];
        }
        int maxi = 0;
        int sum = 0;
        for (int i = 0; i <= k; i++) {
            sum += gap[i];
        }
        maxi = max(maxi, sum);

        int i = 0;
        int j = k;
        while (j < n) {
            sum -= gap[i++];
            sum += gap[++j];
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};