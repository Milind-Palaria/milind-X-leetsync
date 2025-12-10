class Solution {
public:
    int mod=1e9+7;
    int fact(int n){
        long long temp=1;
        for(int i=1;i<=n;i++){
            temp = ((temp%mod)*(i%mod))%mod;
        }
        return (int)temp;
    }
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
        }
        return fact(n-1);
    }
};