class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=nums.size()-1 ; i >= 0 ; i--){
            if(mp.find(nums[i]) != mp.end()){
                return (i+3) / 3;
            }else{
                mp[nums[i]]++;
            }
        }

        return 0;
    }
};