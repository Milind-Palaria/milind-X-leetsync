class Solution {
public:
    int maxDifference(string s) {
        unordered_map <char,int> myMap;
        for(int i = 0 ; i < s.size() ; i++)
        {
            myMap[s[i]] = myMap[s[i]] + 1  ;
        }
        int odd = INT_MIN ;
        int even = INT_MAX ;
        for(auto pair : myMap)
        {
            if(pair.second % 2 == 0 )
            {
                if(pair.second < even)
                {
                    even = pair.second;
                }
            }
            else
            {
                if(pair.second > odd)
                {
                    odd = pair.second;
                }
            }
        }
        return odd - even ;    
    }
};