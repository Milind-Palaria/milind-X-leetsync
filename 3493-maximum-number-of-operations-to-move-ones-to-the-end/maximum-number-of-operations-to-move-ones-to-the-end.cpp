class Solution {
public:
    int maxOperations(string s) {
        int c1=0,ans=0;
        bool flag=true;
        for(auto it:s){
            if(it=='1'){
                c1++;
                flag=false;
            }
            else if(it=='0' && flag==false){
                flag=true;
                ans+=c1;
            }
        }
        return ans;
    }
};