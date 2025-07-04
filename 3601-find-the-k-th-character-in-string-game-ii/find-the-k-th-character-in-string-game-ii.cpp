class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        int n = ops.size();
        int cnt = 0;
        k--;

        for(int i=0; i<n && k!=0; i++, k>>=1){
            cnt += ((k&1) & ops[i]);
        }
        return char ('a' + (cnt%26));
    }
};