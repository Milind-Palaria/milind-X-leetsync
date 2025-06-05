class Solution {
public:
    vector<int> representative;

    int repr(int a) {
        if (representative[a] != a)
            representative[a] = repr(representative[a]);
        return representative[a];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        representative.resize(26);
        for (int i = 0; i < 26; i++) representative[i] = i;

        for (int i = 0; i < s1.size(); i++) {
            int a = repr(s1[i] - 'a');
            int b = repr(s2[i] - 'a');

            if (a != b) {
                if (a < b) representative[b] = a;
                else representative[a] = b;
            }
        }

        string ans;
        for (char c : baseStr) {
            ans.push_back(char(repr(c - 'a') + 'a'));
        }

        return ans;
    }
};