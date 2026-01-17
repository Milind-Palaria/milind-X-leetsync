#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        long long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = max(a[i][0], a[j][0]);
                int y1 = max(a[i][1], a[j][1]);
                int x2 = min(b[i][0], b[j][0]);
                int y2 = min(b[i][1], b[j][1]);

                long long overlapWidth  = (long long)x2 - x1;
                long long overlapHeight = (long long)y2 - y1;

                long long side = min(overlapWidth, overlapHeight);
                if (side > 0) {
                    maxSide = max(maxSide, side);
                }
            }
        }

        return maxSide * maxSide;
    }
};