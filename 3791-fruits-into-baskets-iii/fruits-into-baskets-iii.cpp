class Solution {
    void build(int x, int lx, int rx, vector<int> &baskets, vector<int> &seg) {
        if(rx - lx == 1) {
            if(lx < baskets.size()) seg[x] = baskets[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, baskets, seg);
        build(2 * x + 2, m, rx, baskets, seg);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    int find(int x, int lx, int rx, int v, vector<int> &seg) {
        if(rx - lx == 1) {
            if(seg[x] >= v) {
                seg[x] = 0;
                return lx;
            }
            return -1;
        }
        int m = (lx + rx) / 2;
        int ans = -1;
        if(seg[2 * x + 1] >= v) ans = find(2 * x + 1, lx, m, v, seg);
        else ans = find(2 * x + 2, m, rx, v, seg);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
        return ans;
    }
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        int n = fruits.size(), s = 1, ans = 0;
        for(; s < n; s *= 2) {}
        vector<int> seg(2 * s, 0);
        build(0, 0, n, baskets, seg);
        for(int i = 0; i < n; i++) {
            int tmp = find(0, 0, n, fruits[i], seg);
            if(tmp == -1) ans++;
        }
        return ans;
    }
};