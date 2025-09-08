class Solution {
public:
    bool check(int n){
        while(n>0){
            int t = n%10;
            if(t==0)return false;
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1; i<=n; i++){
            if(check(i) && check(n-i)){
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
        return ans;
    }
};