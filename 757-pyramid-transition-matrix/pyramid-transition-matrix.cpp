class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<int>> allow;
        for(string& s: allowed) allow[string({s[0], s[1]})].push_back(s[2] - 'A');
        return backtrack(bottom, allow, bottom.size());
    }

    bool backtrack(string bottom, unordered_map<string, vector<int>>& allow, int n, int i=0) {
        if(n == 2) return allow[string({bottom[0], bottom[1]})].size();
        if(i == n-1) return backtrack(bottom, allow, n-1, 0);
        for(int& top: allow[string({bottom[i], bottom[i+1]})]) {
            bottom[i] = 'A' + top;
            if(backtrack(bottom, allow, n, i+1)) return true;
        }
        return false;
    }
};