class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;

    int numberOfWays(string corridor) {
        int n = corridor.size();

        ll sum = 0;

        for(char &ch : corridor) {
            if(ch == 'S') {
                sum++;
            }
        }

        if(sum % 2 != 0 || sum == 0) {
            return 0;
        }

        vector<int> sIdx;

        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') {
                sIdx.push_back(i);
            }
        }

        ll ans = 1;

        ll priviousIdx = sIdx[1];
        n = sIdx.size();

        for(int i = 2; i < n; i += 2) {
            ll currIdx = sIdx[i];

            ll diff = currIdx - priviousIdx;
            
            ans = (ans * diff) % M;

            priviousIdx =  sIdx[i+1];
        }

        return ans;
    }
};