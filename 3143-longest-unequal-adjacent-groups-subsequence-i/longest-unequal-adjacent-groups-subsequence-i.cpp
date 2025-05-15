class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string>ans1;
        vector<string>ans2;
        int g=0,i=0;
        while(i<n)
        {
            if(groups[i]==g)
            {
                ans1.push_back(words[i]);
                g=!g;
            }
            i++;
        }
        g=1, i=0;
        while(i<n)
        {
            if(groups[i]==g)
            {
                ans2.push_back(words[i]);
                g=!g;
            }
            i++;
        }
        if(ans1.size()>ans2.size())
        {
            return ans1;
        }
        else return ans2;
    }
};