class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, count = 1, prev = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) count++;
            else {
                res += min(prev, count);
                prev = count;
                count = 1;
            }
        }
        res += min(prev, count);
        return res;
    }
};