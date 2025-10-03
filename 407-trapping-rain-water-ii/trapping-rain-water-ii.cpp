class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;
    int n; 
    UnionFind(int sz): n(sz), parent(sz), rank(sz, 1) {
        iota(parent.begin(), parent.end(), 0);
        rank[sz-1] = 0;
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void uni(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        parent[px] = py;
        rank[py] += rank[px];
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> total;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total.push_back({heightMap[i][j], i, j});
            }
        }
        sort(total.begin(), total.end());
        int ci = 0;
        UnionFind uf(m*n+1);
        vector<vector<bool>> can(m, vector<bool>(n, false));
        int res = 0;
        for(int h = total[ci][0]; h < total.back()[0]; h++) {
            int c = h;
            while(ci < total.size() && total[ci][0] == c) {
                can[total[ci][1]][total[ci][2]] = true;
                if(total[ci][1] == 0 || total[ci][1] == m-1 || total[ci][2] == 0 || total[ci][2] == n-1) {
                    uf.uni((total[ci][1]*n) + total[ci][2], m*n);
                }
                for(int d = 0; d < 4; d++) {
                    int nx = total[ci][1] + dirs[d][0];
                    int ny = total[ci][2] + dirs[d][1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && can[nx][ny]) {
                        uf.uni((total[ci][1]*n) + total[ci][2], n*nx + ny);
                    }
                }
                ci++;
            }
            res += ci - uf.rank[uf.find(m*n)];
        }
        return res;
    }
};