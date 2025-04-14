class Solution {
public:
    long long expo(long long num, long long exp, long long mod) {
        long long ans = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * num) % mod;
            }
            num = (num * num) % mod;
            exp /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        long long ans = 1;
        // for(int i=0;i<n;i++){
        //     if(i % 2== 0){
        //         ans *= 5; 
        //         ans %= mod;
        //     }else{
        //         ans *= 4;
        //         ans %= mod;
        //     }
        // }
        // return (int)ans;
        if(n % 2 == 0){
            ans = (ans*expo(5,n/2,mod))%mod;
            ans = (ans*expo(4,n/2,mod))%mod;
        }else{
            ans = (ans*expo(5,(n+1)/2,mod))%mod;
            ans = (ans*expo(4,n/2,mod))%mod;
        }
        return (int) ans;
    }
};