class Solution {
public:
    string makeFancyString(string s) {
        string ans ="";
        char last;
        int count = 0;
        for(auto ch : s){
            if(ch != last){
                last = ch;
                count = 0 ;
            }
            if(++count >2) continue;
            ans+=ch;
        }
        return ans;
    }
};