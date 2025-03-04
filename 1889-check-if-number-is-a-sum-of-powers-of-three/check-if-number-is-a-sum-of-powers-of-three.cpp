class Solution {
public:
    bool checkPowersOfThree(int n) {
        int store = 0, k = 0;
        
        for (int i = 0; i < n; i++) {
            if (pow(3, i) <= n) {
                store = pow(3, i);
                k = i;
                if (store == n) return true;
            } else break;
        }

        for (int i = k - 1; i >= 0; i--) {
            if (pow(3, i) <= n - store) {
                store += pow(3, i);
                if (store == n) return true;
            }
        }
        return false;
    }
};