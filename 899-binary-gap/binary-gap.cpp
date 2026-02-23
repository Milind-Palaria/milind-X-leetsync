class Solution {
public:
    int binaryGap(int n) {
        int lastOnePosition = -1;
        int currentPosition = 0;
        int maxDistance = 0;

        while (n > 0) {
            bool isCurrentBitOne = (n & 1) == 1;

            if (isCurrentBitOne) {
                if (lastOnePosition != -1) {
                    int currentDistance = currentPosition - lastOnePosition;
                    maxDistance = max(maxDistance, currentDistance);
                }
                lastOnePosition = currentPosition;
            }

            n >>= 1;
            currentPosition++;
        }

        return maxDistance;
    }
};