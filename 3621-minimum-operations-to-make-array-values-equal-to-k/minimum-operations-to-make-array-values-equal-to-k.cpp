class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i : nums){
            mp[i]++;
            if(i<k){
                return -1;
            }
            if(mp[i]==1 && i>k){ // only distinct numbers 
                ans++;
            }
        }
        return ans;
    }
};