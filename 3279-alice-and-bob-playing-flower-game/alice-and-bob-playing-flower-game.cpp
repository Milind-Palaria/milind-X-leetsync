class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_odd = (n+1)/2;
        long long n_even = n - n_odd;
        long long m_odd = (m+1)/2;
        long long m_even = m - m_odd;

        return n_even*m_odd + n_odd*m_even;
    }
};