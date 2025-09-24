class Solution {
public:

string fn(long long a , long long b){
    map<long long ,int>vec; 
    string s = "";
    vec[0] =-1;
    int count = 0;
    while(vec[a] ==0){
        count++;
        vec[a] = count;
        a*=10;
        s+= to_string(a/b);
        a  =a%b;
    }
    if(a){
       
    return s.substr(0,vec[a]-1) + '('+ s.substr(vec[a]-1) + ')';
    }
    else return s;
}
    string fractionToDecimal(int numerator, int denominator) {

        long long a = numerator , b = denominator;
        int f = 1;
        if(a<0)f*=(-1);
        if(b<0) f =  f*(-1);
        a = abs(a);
        b = abs(b);

        long long g = a/b;
        string ans = to_string(g);
      
        if((a%b) ==0)return (f==-1 && !(ans.size()==1 && ans[0] =='0'))? '-' + ans: ans;
        ans+='.';
       
        cout<<f<<" "<<ans<<endl;
        ans+= fn(a%b , b);
        if(f ==-1)ans = '-'+ans;
        return ans;

    }
};