class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int i = 0;
        char c = '-1';
        while(i<s.size()){
            if((s[i]-'0')<9) {
                c = s[i];
                break;
            }
            i++;
        }
        string a = s;
        while(i<a.size()){
            if(a[i]==c){
                a[i] = '9';
            }
            i++;
        }
        char d = '-1';
        int j = 0;
        while(j<s.size()){
            if((s[j]-'0')>0) {
                d = s[j];
                break;
            }
            j++;
        }
        string b = s;
        while(j<b.size()){
            if(b[j]==d){
                b[j] = '0';
            }
            j++;
        }
        return stoi(a)-stoi(b);
    }
};