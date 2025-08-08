class Solution {
    unordered_map<int, unordered_map<int, double>> memo;

    double dfs(int A, int B) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;
        if (memo[A][B]) return memo[A][B];

        return memo[A][B] = 0.25 * (
            dfs(A - 100, B) +
            dfs(A - 75,  B - 25) +
            dfs(A - 50,  B - 50) +
            dfs(A - 25,  B - 75)
        );
    }

public:
    double soupServings(int n) {
        if (n > 5000) return 1.0;
        return dfs(n, n);
    }
};