
class Solution {
public:
    string countAndSay(int n){
        int num = 1;
        int count = 1;
        string s;

        while(num<=n){
            if(num==1)
                s = "1";
            else{
                int i = 0;
                string temp = "";
                while(i < s.size()){
                    if(s[i]==s[i+1]){
                        count++;
                    }
                    else{
                        temp += char(count + '0');
                        temp += s[i];
                        count = 1;
                    }
                    i++;
                }
                s = temp;
            }
            num++;
        }
        return s;
    }
};