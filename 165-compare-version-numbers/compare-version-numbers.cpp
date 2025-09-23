class Solution {
    vector<int> versionToIntVector(const string &version) {
        vector<int> v;
        for (int i = 0, j = 0; j < version.size(); ++j) {
            string val = "-1";
            if (j == version.size() - 1) {
                val = version.substr(i, j - i + 1);
            } else if (version[j] == '.') {
                val = version.substr(i, j - i);
                i = j + 1;
            }
            if (val != "-1") {
                v.push_back(stoi(val));
            }
        }

        return v;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = versionToIntVector(version1);
        vector<int> v2 = versionToIntVector(version2);

        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) return -1;
            else if (v1[i] > v2[j]) return 1;
            ++i, ++j;
        }

        while (i < v1.size()) {
            if (v1[i] > 0) return 1;
            ++i;
        }

        while (j < v2.size()) {
            if (v2[j] > 0) return -1;
            ++j;
        }

        return 0;
    }
};