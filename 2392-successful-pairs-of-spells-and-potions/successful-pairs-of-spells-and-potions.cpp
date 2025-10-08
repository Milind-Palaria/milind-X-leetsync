class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        int n =  spells.size();
        int m = potions.size();

        sort(potions.rbegin(), potions.rend());

        vector<int>ans(n , 0);


        for(int i =0; i< n; i++){

            int l =0, r = m -1;

            int cnt = -1;

            while(l <= r){

                int m = (l + r)>>1;

                if(1LL*spells[i]*potions[m] >= success){

                    cnt = m;

                    l = m +1;
                }else{

                    r = m -1;
                }
            }

            ans[i] = cnt + 1;
        }

        return ans;
        
    }
};