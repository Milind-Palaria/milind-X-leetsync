class FindSumPairs {
private:
    vector<int> n1, n2;
    unordered_map<int, int> map1; 
    unordered_map<int, int> map2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n1) map1[x]++;
        for (int x : n2) map2[x]++;
    }

    void add(int index, int val) {
        int oldVal = n2[index];
        map2[oldVal]--;
        if (map2[oldVal] == 0) map2.erase(oldVal);

        n2[index] += val;
        map2[n2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for (const auto& [num1, freq1] : map1) {
            int needed = tot - num1;
            if (map2.count(needed)) {
                result += freq1 * map2[needed];
            }
        }
        return result;
    }
};