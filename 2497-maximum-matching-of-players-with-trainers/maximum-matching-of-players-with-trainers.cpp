class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        int i = 0, j = 0, c = 0;
        while (i < p.size() && j < t.size()) {
            if (p[i] <= t[j]) {
                c++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return c;
    }
};