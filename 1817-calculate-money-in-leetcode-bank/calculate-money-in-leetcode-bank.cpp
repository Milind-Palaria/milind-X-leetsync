class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int week = i / 7 + 1;
            int day = i % 7;
            ans += week + day;
        }

        return ans;
    }
};