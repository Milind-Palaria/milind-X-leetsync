class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>v;
        vector<pair<int,int>>p;
        for(int i=0;i<nums.size();i++){
            p.push_back({nums[i],i});
            nums[i]=-100005;
        }
        sort(p.rbegin(),p.rend());
        int i=0;
        while(k){
            nums[p[i].second]=p[i].first;
            i++;k--;
        }
        for(auto u:nums){
            if(u!=-100005){
                v.push_back(u);
            }
        }
        return v;
    }
};