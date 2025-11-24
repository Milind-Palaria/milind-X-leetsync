class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>m;
        int r=0;
        for(int mm:nums){
            r=(r*2+mm)%5;
            m.push_back(r==0);
            }
         return m;
    }
};