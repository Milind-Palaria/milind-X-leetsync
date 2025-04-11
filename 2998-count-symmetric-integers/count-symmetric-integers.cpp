class Solution {
    bool digitCompare(int n) {
        if (n < 100 && n % 11 == 0) {
            return true;
        } else if (1000 <= n && n < 10000) {
            int left = n / 1000 + (n % 1000) / 100;
            int right = (n % 100) / 10 + n % 10;

            return left == right;
        }

        return false;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        vector<int> output;

        for (int i = low; i <= high; i++) {
            if (digitCompare(i)) {
                output.push_back(i);
            }
        }

        return output.size();
    }
};