class Solution {
    #define ll long long
public:
    long long distributeCandies(int n, int limit) {
        ll ans=0;
        for(ll i=0;i<2;i++){
            for(ll j=0;j<2;j++){
                for(ll k=0;k<2;k++){
                    ll sign=pow(-1,i+j+k);
                    ll val=n-(i+j+k)*(limit+1);
                    if(val>=0)ans+=sign*(((val+2)*(val+1))/2);
                }
            }
        }
        return ans;
    }
};