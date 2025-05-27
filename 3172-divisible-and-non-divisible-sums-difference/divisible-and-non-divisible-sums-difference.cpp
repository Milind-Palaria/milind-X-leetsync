class Solution {
public:
    int differenceOfSums(int n, int m) {
        int multiplesOfM = n / m;
        int sum1 = n * (n + 1) / 2;
        int sum2 = m * (multiplesOfM * (multiplesOfM + 1) / 2);
        return sum1 - 2 * sum2;
    }
};