class Solution {
private:
    string rotateByB(string s, int b) { return s.substr(b) + s.substr(0, b); }

    string addAToOddIndices(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }

        return s;
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);

        string mini = s;
        unordered_set<string> vis;
        vis.insert(s);
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            mini = min(mini, str);

            string rotate = rotateByB(str, b);
            string add = addAToOddIndices(str, a);

            if (vis.find(rotate) == vis.end()) {
                q.push(rotate);
                vis.insert(rotate);
            }
            if (vis.find(add) == vis.end()) {
                q.push(add);
                vis.insert(add);
            }
        }

        return mini;
    }
};