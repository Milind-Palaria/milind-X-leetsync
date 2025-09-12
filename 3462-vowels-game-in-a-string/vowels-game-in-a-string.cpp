class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(auto x : s){
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ){
             count++;
             if(count>0){
                return true;
             }
            }
        }
        
        return false;

        
    }
};