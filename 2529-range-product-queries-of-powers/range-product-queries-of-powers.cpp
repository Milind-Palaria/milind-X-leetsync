class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> getpower(int n){
        vector<int> power;
        int k=1;
        while(n>0){
            if(n%2)
                power.push_back(k);
            n/=2;
            k*=2;
        }
        return power;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power=getpower(n);
        vector<int>res;
        for(auto vec:queries){
            long long pro=1;
            for(int j=vec[0];j<=vec[1];j++){
                pro=(pro*power[j])%MOD;
            }
            res.push_back(pro);
        }
        return res;
    }
};