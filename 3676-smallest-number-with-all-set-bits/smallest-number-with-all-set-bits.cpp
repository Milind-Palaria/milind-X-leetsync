class Solution {
public:
    int smallestNumber(int n) {
        for (int i = 10; i >= 0; i--) {
            int bit = 1 & (n >> i);
            if (bit) {
                return (1 << (i + 1)) - 1;
            }
        }
        return 1;
    }
};