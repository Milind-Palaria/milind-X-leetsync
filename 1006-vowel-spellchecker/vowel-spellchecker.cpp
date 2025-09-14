class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> caseMap;
        unordered_map<string,string> vowelMap;
        
        auto devowel = [](string w) {
            for (auto &c : w) {
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c='*';
            }
            return w;
        };
        
        for (string w : wordlist) {
            string lower = w;
            for (auto &c : lower) c = tolower(c);
            if (!caseMap.count(lower)) caseMap[lower] = w;
            
            string vow = lower;
            vow = devowel(vow);
            if (!vowelMap.count(vow)) vowelMap[vow] = w;
        }
        
        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            
            string lower = q;
            for (auto &c : lower) c = tolower(c);
            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
                continue;
            }
            
            string vow = devowel(lower);
            if (vowelMap.count(vow)) {
                ans.push_back(vowelMap[vow]);
                continue;
            }
            
            ans.push_back("");
        }
        
        return ans;
    }
};