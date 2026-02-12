class Solution {
public:                                            
    int longestBalanced(string s) {
    int n = s.size();
    int ans = 0;

    for(int i = 0; i < n; i++) {

        unordered_map<char,int> mp;   

        for(int j = i; j < n; j++) {

            mp[s[j]]++; 

            // check if balanced
            int same = 1;
            int freq = -1;

            for(auto it : mp) {
                if(freq == -1)
                    freq = it.second;
                else {
                    if(it.second != freq) {
                        same = 0;
                        break;
                    }
                }
            }

            if(same == 1) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    return ans;
    }
};