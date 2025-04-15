class Solution {
public:
    struct BIT {
        vector<int> tree;
        int n;

        BIT(int size) : n(size) {
            tree.resize(size+2, 0);
        }

        void update(int index, int value) {
            for (++index; index <= n+1; index += index & -index)
                tree[index] += value;
        }

        int query(int index) {
            int result = 0;
            for (++index; index > 0; index -= index & -index)
                result += tree[index];
            return result;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i)
            pos2[nums2[i]] = i;

        vector<int> positions(n);
        for (int i = 0; i < n; ++i)
            positions[i] = pos2[nums1[i]];

        BIT leftBIT(n), rightBIT(n);
        for (int i = 0; i < n; ++i)
            rightBIT.update(positions[i], 1);

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            rightBIT.update(positions[i], -1);
            int leftCount = leftBIT.query(positions[i] - 1);
            int rightCount = rightBIT.query(n-1) - rightBIT.query(positions[i]);
            result += 1LL * leftCount * rightCount;
            leftBIT.update(positions[i], 1);
        }
        return result;
    }
};