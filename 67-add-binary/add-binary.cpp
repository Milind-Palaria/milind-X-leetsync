class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        int i=n-1,j=m-1;
        string ans = "";
        int carry = 0;

        while(i>=0 and j>=0){
            int v1 = a[i]-'0';
            int v2 = b[j]-'0';

            int sum = (v1+v2+carry);
            // cout<<"1->"<<sum<<"\n";

            if(sum >=2){
                carry = 1;
            }else{
                carry = 0;
            }
            // cout<<"1->"<<((sum%2))<<"\n";
            ans += (to_string(sum%2));
            i--;
            j--;
        }

        while(i>=0){
            int v1 = a[i]-'0';
            int sum = (v1+carry);

            if(sum >= 2){
                carry = 1;
            }else{
                carry = 0;
            }
            // cout<<"2->"<<((sum%2))<<"\n";
            ans += (to_string(sum%2));
            i--;
        }

        while(j>=0){
            int v1 = b[j]-'0';
            int sum = (v1+carry);

            if(sum >= 2){
                carry = 1;
            }else{
                carry = 0;
            }
            // cout<<"3->"<<(sum%2)<<"\n";
            ans += (to_string(sum%2));
            j--;
        }

        if(carry==1){
            ans +='1';
        }



        reverse(ans.begin(), ans.end());

        return ans;
    }
};