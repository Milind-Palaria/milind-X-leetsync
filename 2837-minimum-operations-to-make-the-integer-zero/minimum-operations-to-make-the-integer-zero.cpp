class Solution {
public:
    int noOfSetBits(long long n){
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int n = 1; n <= 60; n++) {
            long long k = 1LL * num1 - 1LL * n * num2;
            if (k < 0) break;
            if (noOfSetBits(k) <= n && k >= n) {
                return n;
            }
        }
        return -1;
    }
};