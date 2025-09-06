class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long totalOps = 0;
        
        for (auto& q : queries) {
            long long l = q[0], r = q[1];
            long long ops = 0;
            long long level = 1, base = 1;
            
            while (base <= r) {
                long long nextBase = base * 4;
                
                long long left = max(l, base);
                long long right = min(r, nextBase - 1);
                
                if (left <= right) {
                    long long num = right - left + 1;
                    ops += num * level;   }
                
                base = nextBase;
                ++level;
            }
            
            totalOps += (ops + 1) / 2;
        }
        
        return totalOps;
    }
};