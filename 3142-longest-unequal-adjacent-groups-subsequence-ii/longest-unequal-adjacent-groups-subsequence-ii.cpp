class Solution {
public:
    static bool hamming1(const string& a, const string& b) {
        if(a.size() != b.size()) return false;
        int diff = 0;
        for(int i = 0; i < a.size() && diff < 2; ++i)
            diff += (a[i] != b[i]);
        return diff == 1;
    }

    static vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), maxLen = 0, last = -1;
        vector<int> dp(n, 1), prev(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && hamming1(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                last = i;
            }
        }
        vector<string> res;
        while (last != -1) {
            res.push_back(words[last]);
            last = prev[last];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};