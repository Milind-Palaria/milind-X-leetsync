class Solution {
    long long solve(string num, int limit, string s) {
        if(num.length() <= s.length()) return stol(num) >= stol(s);
        int prefixLen = num.length() - s.length();
        long long ans = 0;
        for(int i = 0; i < prefixLen; i++) {
            if((num[i] - '0') > limit) {
                return ans + pow(limit + 1L, prefixLen - i);
            }
            ans += (num[i] - '0') * pow(limit + 1L, prefixLen - i - 1);
        }
        return ans + (num.substr(num.length() - s.length()) >= s);
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(to_string(finish), limit, s) - solve(to_string(start - 1), limit, s);
    }
};