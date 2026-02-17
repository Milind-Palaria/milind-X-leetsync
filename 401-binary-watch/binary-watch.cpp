class Solution {
public:
    int count(int n){
        int cnt=0;
        while(n>0){
            if(n%2 == 1){
                cnt++;
            }
            n=n/2;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>res;

        for(int i=0;i<=11;i++){
            int c1=count(i);
            for(int j=0;j<=59;j++){
                string temp="";
                if(c1+count(j) == turnedOn){
                    temp += to_string(i)+":";
                    if(j < 10){
                        temp += "0";
                    }
                    temp += to_string(j);
                }
                if(temp != ""){
                res.push_back(temp);
                }
            }
        }
        return res;
    }
};