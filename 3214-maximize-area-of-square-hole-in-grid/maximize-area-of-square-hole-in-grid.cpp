class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        int row = 1, cnt = 1, col = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        for(int i = 1; i < (int)hBars.size(); ++i) {

            if(hBars[i] == hBars[i - 1] + 1) {

                cnt++;
            }
            else {

                cnt = 1;
            }

            row = max(row, cnt);
        }

        cnt = 1;

        for(int i = 1; i < (int)vBars.size(); ++i) {

            if(vBars[i] == vBars[i - 1] + 1) {

                cnt++;
            }
            else {

                cnt = 1;
            }

            col = max(col, cnt);
        }

        int length = min(row, col) + 1;

        return length * length;
    }
};