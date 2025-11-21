class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ret = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int first = -1, last = -1;
            unordered_map<char, int> other;
            for (int i = 0; i < s.size(); i ++) {
                if (s[i] == c) {
                    if (first == -1) {
                        first = i;
                    }
                    last = i;
                }
            }
            if (last - first <= 1) {
                continue;
            }
            for (int i = first + 1; i < last; i ++) {
                other[s[i]]++;
            }
            ret += other.size();
            
        }
        return ret;
    }
};