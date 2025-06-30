class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int &num :nums){
            mp[num]++;
        }


        int res=0;
        for(int & x : nums){
            int num=x;
            int maxnums=x+1;
            if(mp.count(maxnums)){
                res=max(res,mp[num]+mp[maxnums]);
            }
        }
        return res;
    }
};